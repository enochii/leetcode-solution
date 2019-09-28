// https://leetcode.com/problems/sum-of-distances-in-tree/solution/
//两次dfs...

// 834. Sum of Distances in Tree
//dfs

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> child(N,0);
        vector<int> ans(N,0);
        
        vector<vector<int>> graph(N);
        
        for(auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, graph, child, ans,-1);
        dfs1(0,graph,child,ans,-1);
        
        return ans;
    }
    
    //先算出所有节点拥有的孩子数量 以及 某节点到其所有子节点需要的总步数
    //这轮dfs结束后，事实上，根节点已经拥有了答案
    void dfs(int root, vector<vector<int>>& graph, vector<int>& child, vector<int>& cnt, int par){
        for(int c:graph[root]){
            if(par == c)continue;
            dfs(c, graph,child,cnt,root);
            child[root]+=child[c]+1;//c分支拥有的孩子数
            cnt[root]+=cnt[c]+(child[c]+1);//在分支c的基础上还要再走一步
        }
        
    }
    
    //从父亲反推答案
    void dfs1(int root, vector<vector<int>>& graph, vector<int>& child, vector<int>& cnt, int par){
        const int N = child.size();
        for(int c:graph[root]){
            if(c == par)continue;
            cnt[c] = cnt[root] - (child[c]+1) + N - (child[c]+1);
            dfs1(c,graph,child,cnt,root);
        }
    }
};