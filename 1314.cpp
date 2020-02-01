class Solution {
    // dp[i][j] 表示 从 [0, 0] -> [i, j]的和
    // answer 矩阵可以通过 dp 做出来
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        const int m = mat.size();
        const int n = m? mat[0].size():0;
        
        if(!m || !n)return {};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        //第一行
        dp[0][0] = mat[0][0];
        for(int i=1;i<n;i++)
        {
            dp[0][i] = dp[0][i-1] + mat[0][i];
        }
        
        //
        for(int i = 1;i<m;i++)
        {
//             dp[i][0] = mat[i][0] + dp[i-1][0];
            
            int cur_level_sum = 0;
            for(int j = 0; j<n;j++)
            {
                cur_level_sum += mat[i][j];
                dp[i][j] = cur_level_sum + dp[i-1][j];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sr = max(i-k, 0);
                int sc = max(j-k, 0);
                int er = min(m-1, i+k);
                int ec = min(n-1, j+k);
                
                int lt, rt, lb, rb;
                //注意边界条件 sr / sc ...
                // 根据 dp 矩阵 生成 ans 矩阵
                // 其实就是 矩阵和的加减法（相邻矩阵组合生成新的矩阵）
                // sr 和 sc 为零 时，需要特殊讨论

                //可以用额外的空间省去 if 判断
                if(sr == 0 || sc == 0)lt=0;else lt = dp[sr-1][sc-1];
                if(sr == 0)rt=0;else rt = dp[sr-1][ec];
                
                if(sc == 0)lb=0;else lb = dp[er][sc-1];
                
                rb = dp[er][ec];
                
                ans[i][j] = rb + lt - rt - lb;
            }
        }
        
        return ans;
    }
};  