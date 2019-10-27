// 743. Network Delay Time
class Solution {
    const int MAX_DIS = 6001;
public:
    //dijkstra
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
