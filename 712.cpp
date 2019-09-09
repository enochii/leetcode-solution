#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 712. Minimum ASCII Delete Sum for Two Strings
// Edit Distance

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int sz1=s1.size(),sz2=s2.size();
        if(sz1==0&&sz2==0){
            return 0;
        }
        vector<vector<int>> dp(sz1+1,vector<int>(sz2+1,0));
        //dp[i][j]表示使得[i,end)和[j,end)相同的最小删除和
        //删除i或者删除j，跟编辑距离区别的是没有替换，所以状态转换相对简单
        //dp[i][j]=min(dp[i][j+1]+i, dp[i+1][j]+j)
        //先求最后一行
        // dp.back().back()=0;
        for(int i=sz2-1;i>=0;i--){
            dp.back()[i]=dp.back()[i+1]+s2[i];
        }
        //
        for(int i=sz1-1;i>=0;i--){
            dp[i].back()=dp[i+1].back()+s1[i];
            for(int j=sz2-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    dp[i][j]=min({
                        // dp[i+1][j+1]+s1[i]+s2[j],
                    dp[i][j+1]+s2[j],dp[i+1][j]+s1[i]
                    });
                }
            }
        }
        // for(int i=0;i<=sz1;i++){
        //     for(int j=0;j<=sz2;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        return dp[0][0];
    }
};