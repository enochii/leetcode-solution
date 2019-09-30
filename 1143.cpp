// 1143. Longest Common Subsequence
//DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp问题
        //dp[i][j]表示t1前i个字符和t2前j个字符组成的LCS
        //t1[i] == t2[j] -> dp[i][j] = dp[i-1][j-1] + 1
        //                  dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1));
        for(int i=0;i<text1.size();i++){
            for(int j=0;j<text2.size();j++){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = 1+ dp[i][j];
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        //
        return dp.back().back();
    }
};