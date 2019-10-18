// 785. Is Graph Bipartite?

//把节点分成subet
//使得所有边的两个节点分别在两个subset中
//并查集？
//对于i的graph[i]必然在同一个subset，否则他们总会有人和i同个subset

//对于每个graph[i]，先把他们并起来，最后检测i是否在这个并查集中
class _Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty())return true;
        // int n=0;
        // for(auto & v:graph){
        //     for(auto & i:v){
        //         n = max(i+1, n);
        //     }
        // }
        int n = graph.size();
        
        vector<int> fa(n, -1);
        for(int i=0;i<graph.size();i++){
            
            if(graph[i].empty())continue;
            int first = graph[i][0];
            int ffa = find(first, fa);
            for(int j=1;j<graph[i].size();j++){
                int fa1 = find(graph[i][j], fa);
                if(fa1 == ffa)continue;
                fa[fa1] = ffa;
            }
            int fai = find(i, fa);
            if(fai == ffa)return false;
        }
        return true;
    }
    
    int find(int c, vector<int>& fa){
        if(fa[c] == -1)return c;
        return fa[c] = find(fa[c], fa);
    }
};

// dfs和bfs好像是比较大众的思路
// 就变成了一个染色问题
// 从某个节点出发，标记为0
// 下一波节点标记为1，若发现当前节点已经被标记成0则return false
// 从1开始同理

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        
        queue<int> q;
        vector<int> color(n, -1);
        
        for(int src=0;src<n;src++){
            if(color[src]!=-1)continue;
            
            bool tag = false;
            color[src] = tag;
            q.push(src);

            while(!q.empty()){
                const int sz = q.size();
                tag = !tag;

                for(int i=0;i<sz;i++){
                    int top = q.front();q.pop();
                    for (int i:graph[top]){
                        if(color[i]!=-1){
                            if(color[i] == tag)continue;
                            else return false;
                        }
                        color[i] = tag;
                        q.push(i);
                    }
                }
            }
        }
        
        return true;
    }
};