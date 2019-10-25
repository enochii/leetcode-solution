// 1219. Path with Maximum Gold
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        //在这一层可以只从边角出发
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                ans = max(gold(grid,i,j), ans);
            }
        }
        return ans;
    }
    
    int gold(vector<vector<int>> & grid, int x, int y){
        if (grid[x][y] <= 0)return 0;
        grid[x][y] = -grid[x][y];
        static int dir[5] = {1,0,-1,0,1};
        
        int next = 0;
        for(int i=0;i<4;i++){
            int nx = dir[i] + x;
            int ny = dir[i+1] + y;
            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size())continue;
            
            next = max(next, gold(grid, nx, ny));
        }
        
        grid[x][y] = -grid[x][y];
        // cout << next << ' ' << grid[x][y]<<'\n';
        return next+grid[x][y];
    }
};