// 695. Max Area of Island

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  //咋感觉做过...
  //DFS  
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0)return 0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int ans=0;
        // int m=grid.size(),n=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j])continue;
                ans=max(ans,dfs(grid,i,j,vis));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int r,int c,
    vector<vector<bool>>& vis){
        vis[r][c]=true;
        if(grid[r][c]==0)return 0;
        int m=grid.size(),n=grid[0].size();
        int ret=1;
        static int dir[5]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+dir[i],nc=c+dir[i+1];
            if(!valid(nr,nc,m,n)||vis[nr][nc])continue;
            ret+=dfs(grid,nr,nc,vis);
        }
        return ret;
    }
    
    bool valid(int r, int c, int mr, int mc){
        return r<mr&&r>=0&&c>=0&&c<mc;
    }
};