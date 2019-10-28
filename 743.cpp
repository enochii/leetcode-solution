// 743. Network Delay Time
//O(E^2)
class _Solution {
    const int MAX_DIS = 6001;
public:
    //好像是Bellman
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        bool flag = true;
        
        vector<int> dist(N+1, MAX_DIS);
        dist[K] = 0;
        while(flag){
            flag = false;//当前如果没更新边就直接跳出
            
            for(auto & time : times){
                if(dist[time[0]] == MAX_DIS)continue;
                
                if(dist[time[0]] + time[2] < dist[time[1]]){
                    dist[time[1]] = dist[time[0]] + time[2];
                    flag = true;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<N;i++){
            ans = max(dist[i+1], ans);
        }
        return ans == MAX_DIS? -1 : ans;
    }
};

//TODO
class Solution {
    const int MAX_DIS = 6001;
public:
    //dijkstra
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int,int>> > graph(N);
        
        for(auto& time : times){
            //-1 处理
            graph[time[0]-1].emplace_back(time[1]-1, time[2]);
        }
        
        vector<int> dist(N, MAX_DIS);
        vector<bool> vis(N, false);
        dist[K-1] = 0;
        
        bool flag =true;
        while(flag){
            flag = false;
            int mini = -1;
            int dis = MAX_DIS;
            for(int i=0;i<N;i++){
                if(!vis[i] && dis > dist[i]){
                    mini = i;
                    dis = dist[i];
                    flag = true;
                }
            }
            
            if(mini == -1)break;
            vis[mini] = true;
            
            for(auto& p:graph[mini]){
                if(!vis[p.first] && dist[p.first] > dist[mini] + p.second){
                    // flag = true;
                    dist[p.first] = dist[mini] + p.second;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<N;i++){
            ans = max(dist[i], ans);
        }
        return ans == MAX_DIS? -1 : ans;
    }
};