#include <vector>
#include <algorithm>

using namespace std;

//dp简单题
class _Solution {
int m, n;
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = m?grid[0].size():0;
        if(n==0)return 0;
        
        vector<vector<int>> dis(m,vector<int>(n,-1));
        dis[m-1][n-1]=0;
        return grid[0][0]+pathsum(grid, dis,0,0);
        
    }
    
    int pathsum(vector<vector<int>>& grid, vector<vector<int>>& dis, int i,int j){
        if(i<0||j<0||i>=m||j>=n)return -1;//非法pos
        if(dis[i][j]>0)return dis[i][j];
        
        int r = pathsum(grid,dis,i,j+1);
        int d = pathsum(grid,dis,i+1,j);
        
        int sum = r==-1?INT_MAX:r+grid[i][j+1];
        sum = min(sum, d==-1?INT_MAX:d+grid[i+1][j]);

        return dis[i][j] = sum;
    }
};

//迭代版本的dp
//注意下边界条件就行
//迭代还省了一手内存...直接用原数组 施某佩服
class Solution {
int m, n;
public:
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = m?grid[0].size():0;
        if(n==0)return 0;

        for(int i=n-2;i>=0;i--){
            grid[m-1][i]+=grid[m-1][i+1];
        }
        for(int i=m-2;i>=0;i--){
            grid[i][n-1]+=grid[i+1][n-1];
            for(int j=n-2;j>=0;j--){
                grid[i][j]=min(grid[i][j+1], grid[i+1][j])+grid[i][j];
            }
        }
        return grid[0][0];
    }
};