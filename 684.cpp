class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //这样应该必定会形成一个环
        //那么我们先把度为1的点删除
        //剩下的便是一个环
        //只要把该环的一条边拆了就行
        //就拆最后出来的那条边
        
        //因为只有一条多余的边，所以边数即节点数
        const int n = edges.size();
        
        vector<vector<int>> graph(n);
        
        vector<int> deg(n, 0);
        for(auto &edge:edges){
            deg[edge[0] - 1]++;
            deg[edge[1] - 1]++;
            graph[edge[0] - 1].push_back(edge[1] - 1);
            graph[edge[1] - 1].push_back(edge[0] - 1);
        }
        //
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i] == 1)q.push(i);
        }
        //
        
        vector<int> vis(n, 0);
        while(!q.empty()){
            //无向图，不需要层次访问
            // int sz = q.size();
            // for(int i=0;i<sz;i++){
                int top = q.front();
                q.pop();
                vis[top] = 1;
                for(int dest:graph[top]){
                    if(--deg[dest] == 1)q.push(dest);
                }
            // }
        }
        // for(int i=0;i<n;i++)cout<<vis[i]<<' ';
        //
        for(int i=edges.size()-1;i>=0;i--){
            auto& edge = edges[i];
            if(!vis[edge[0]-1] && !vis[edge[1]-1]){
                return edge;
            }
        }
        return {};
    }
};