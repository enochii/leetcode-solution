//可以从四周往中间靠
// 1020. Number of Enclaves
class Solution {
    int m, n;
public:
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size(), n = m?A[0].size():0;
        if(!m || !n)return 0;
        
        for(int i=0;i<n;i++){
            dfs(0,i,A);
            dfs(m-1,i,A);
        }
        
        for(int i=0;i<m;i++){
            dfs(i,0,A);
            dfs(i,n-1,A);
        }
        
        int ans = 0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j] > 0)ans ++;
            }
        }
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<int>> & A){
        
        if(A[r][c] <= 0)return;
        A[r][c] = - A[r][c];
        static int dir[5] = {1,0,-1,0,1};
        
        for(int i=0;i<4;i++){
            int x = r + dir[i];
            int y = c + dir[i+1];
            
            if(x<0||x>=m || y<0 || y>=n){
                continue;
            }
            dfs(x,y,A);
        }
    }
};