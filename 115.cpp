// 115. Distinct Subsequences

//感觉这个dp状态方程好难
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size() < t.size())return 0;
        //dp[i][j]表示当s用了前i+1个字符时，匹配到t的前j个字符有多少种方法
        //s[i] != t[j] -> dp[i][j] = dp[i-1][j]
        //        else -> dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        vector<vector<long long>> dp(s.size(),vector<long long>(t.size()+1,0));
        dp[0][0]=1;
        // for(int j=0;j<t.size();j++){
        //     dp[0][j+1] = dp[0][j];
        // }
        if(s[0] == t[0]) dp[0][1] = 1;
        
        for(int i=1;i<s.size();i++){
            dp[i][0] = 1;
            for(int j=0;j<=i && j<t.size();j++){
                dp[i][j+1] = dp[i-1][j+1];
                if(s[i] == t[j]){
                    dp[i][j+1]+=dp[i-1][j];
                }
            }
        }
        
        return dp.back().back();
    }
};