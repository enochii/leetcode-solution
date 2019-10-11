//最简单的方法就是扫描两次喽
//如果把海洋看成终点，这种做法是从起点走向终点
//需要解决的问题是，相邻节点之间可能高度相同，递归爆栈，需要处理好这个问题
//可以在第一遍递归的过程中不要穿越相同高度的邻接节点
//第二次dfs把再对相同节点进行处理
//我放弃了...

// class Solution {
//     int dir[5] = {0, -1, 0, 1, 0};
// public:
//     // -1 : unvisited
//     // 0  : no way
//     // 1  : A
//     // 2  : P
//     // 3  : A & P
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
//         if(matrix.empty() || matrix[0].empty()) return {};
        
//         const int m = matrix.size();
//         const int n = matrix[0].size();
//         vector<vector<int>> mp(m, vector<int>(n, -1));

//         vector<vector<int>> ans;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 dfs(i,j,mp,matrix);
//                 // cout<<mp[i][j]<<' ';
//             }
//             // cout<<'\n';
//         }
//         vector<vector<int>> vis(m,vector<int>(n,0));
        
        
        
//         return ans;
//     }
    
    
//     int dfs2(int r, int c, vector<vector<int>>& mp, vector<vector<int>> matrix){
//         return 0;
//     }
    
//     int dfs(int r, int c, vector<vector<int>>& mp, vector<vector<int>> matrix){
//         if(r >= mp.size() || c >= mp[0].size())return 1;
//         if(r < 0 || c < 0)return 2;
//         if(mp[r][c] >= 0)return mp[r][c];
        
        
//         int h = matrix[r][c];
        
        
//         int atl = 0;
//         int pac = 0;
//         for(int i=0;i<4;i++){
//             int x = r+dir[i];
//             int y = c+dir[i+1];
            
//             // if(px == x || py == y)continue;
//             if(valid(x,y,mp.size(),mp[0].size()) && h <= matrix[x][y])continue;
//             int ret = dfs(x,y,mp,matrix);
//             if(ret==1)atl = 1;
//             else if(ret==2)pac = 2;
//             else if(ret==3){
//                 atl=1;
//                 pac=2;
//             }
//         }
//         return mp[r][c] = atl+pac;
//     }
//     bool valid(int x, int y, int m, int n){
//         return x >= 0 && y >= 0 && x < m && y < n;
//     }
// };

//感觉方向和以往的dfs不太一样
//有点像终点到起点
class Solution {
    int dir[5] = {0, -1, 0, 1, 0};
    int m,n;
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = m==0?0:matrix[0].size();
        if(m == 0 || n == 0)return {};
        
        vector<vector<int>> pac(m,vector<int>(n,0));
        vector<vector<int>> atl(m,vector<int>(n,0));
        
        // vector<vector<bool>> vis(m,vector<bool>(n,false));

        
        for(int i=0;i<m;i++){
            dfs(i,0,pac,matrix);
            dfs(i,n-1,atl,matrix);
        }
        //
        for(int i=0;i<n;i++){
            dfs(0,i,pac,matrix);
            dfs(m-1,i,atl,matrix);
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==1&&atl[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<int>>& tag, vector<vector<int>>& matrix, int parh=0){
        if(r < 0 || c < 0 || r >= m || c >= n){
            return;
        }
        //不要重复访问已经成功标记的节点
        //但是一个节点如果没有被标记为1，那么它可能被多次访问！
        if(tag[r][c])return;
        if(matrix[r][c] < parh)return;
        
        //
        tag[r][c] = 1;
        for(int i=0;i<4;i++){
            int x = r+dir[i];
            int y = c+dir[i+1];
            
            dfs(x,y,tag,matrix,matrix[r][c]);
        }
        
    }
};