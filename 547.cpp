// 547. Friend Circles

//求连通分量 dfs

#include <vector>

using namespace std;

class _Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty())return 0;
        vector<int> vis(M.size(),false);
        const int n=M.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(M,i,vis);
                cnt++;
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<int>>& M, int beg,vector<int>& vis){
        vis[beg]=true;
        for(int i=0;i<M[beg].size();i++){
            if(vis[i]==false&&M[beg][i]==1)dfs(M,i,vis);
        }
    }
};

// Union Find
class Solution{
public:
    int findCircleNum(vector<vector<int>>& M) {  
        vector<int> fa(M.size(),-1);
        for(int i=0;i<M.size();i++){
            for(int j=0;j<M[0].size();j++){
                if(M[i][j]==0)continue;
                int ifa=find(fa,i);
                int jfa=find(fa,j);
                if(ifa==jfa)continue;
                fa[jfa]=ifa;
            }
        }
        //
        int ans=0;
        for(auto p:fa){
            if(p==-1)ans++;
        }
        return ans;
    }

    int find(vector<int>& fa, int i){
        if(fa[i]==-1)return i;
        return fa[i]=find(fa,fa[i]);
    }
};