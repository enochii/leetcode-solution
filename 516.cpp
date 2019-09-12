// 516. Longest Palindromic Subsequence

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//DP
//就是状态转换方程换了下
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()<2)return s.size();
        const int sz=s.size();
        vector<vector<int>> dp(sz,vector<int>(sz,0));
        dp[0][0]=1;
        for(int i=1;i<sz;i++){
            dp[i][i]=1;
            if(s[i]==s[i-1])dp[i-1][i]=2;
            else dp[i-1][i]=1;
        }
        //
        for(int len=3;len<=sz;len++){
            for(int start=0;start+len<=sz;start++){
                if(s[start]==s[start+len-1]){
                    dp[start][start+len-1]=dp[start+1][start+len-2]+2;
                }else{
                    dp[start][start+len-1]=max(dp[start][start+len-2],dp[start+1][start+len-1]);
                }
            }
        }
        return dp[0][sz-1];
    }
};