#include <vector>

using namespace std;

//用dfs吧,把走过的点都做下标记...
//'#' '0'
//计算连通分量(?)的个数
class Solution {
int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = m?grid[0].size():0;

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++cnt;
                }
            }
        }
        return cnt;

    }
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(j<0||j>=n||i<0||i>=m)return;
        char& c = grid[i][j];
        if(c=='0')return;

        c='0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
};