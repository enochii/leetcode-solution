#include <vector>
#include <string>

using namespace std;

//背包... DP
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[k][i][j]=max(dp[k-1][i][j],dp[k-1][i-cnt0][j-1cnt1]+1)
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto&str :strs){
            int cnt[2]={0};
            for(int i=0;i<str.size();i++){
                cnt[str[i]-'0']++;
            }
            //
            for(int i=m;i>=0;i--){
                for(int j=n;j>=0;j--){
                    if(cnt[0]<=i&&cnt[1]<=j
                    && dp[i][j]<dp[i-cnt[0]][j-cnt[1]]+1){
                        dp[i][j]=dp[i-cnt[0]][j-cnt[1]]+1;
                    }
                }
            }
            //
        }
        return dp[m][n];
    }
};