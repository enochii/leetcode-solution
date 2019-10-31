// 1130. Minimum Cost Tree From Leaf Values
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        
        //dp[i][j]表示子数组[i:j]的mct
        //dp[i][j] = maxLeaf[i][k] * maxLeaf[k][j] + dp[i][k] + dp[k][j]
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> maxLeaf(n, vector<int>(n));
        
        for(int i=0;i<n;i++){
            dp[i][i] = 0;
            maxLeaf[i][i] = arr[i];
        }
        
        for(int len = 2;len <= n; len++){
            for(int start = 0;start+len <= n;start++){
                //dp[start][start+len-1]
                int end = start+len-1;
                dp[start][end] = INT_MAX;
                for(int mid = start;mid<end;mid++){
                    int ll = maxLeaf[start][mid], rl = maxLeaf[mid+1][end];
                    dp[start][end] = 
                        min(dp[start][mid]+dp[mid+1][end] 
                        + ll * rl, dp[start][end]);
                    maxLeaf[start][end] = max(ll, rl);
                    // cout << start << ' ' << end << ' ' << dp[start][end] <<' '<<maxLeaf[start][end]<<'\n';
                }
                // cout<<"|\n";
            }
        }
        return dp[0][n-1];
    }
};