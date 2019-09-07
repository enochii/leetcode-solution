// 63. Unique Paths II

#include <vector>

using namespace std;

class _Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m=obstacleGrid.size();
        if(m==0)return 0;
        const int n=obstacleGrid[0].size();
        if(n==0||obstacleGrid.back().back()==1)return 0;
        //
        vector<vector<long long>> cnt(m,(vector<long long>(n,0)));
        cnt.back().back()=1;
        for(int i=n-2;i>=0;i--){
            if(obstacleGrid[m-1][i]==0 && cnt[m-1][i+1]){
                cnt[m-1][i]=1;
            }else break;
        }
        //
        for(int i=m-2;i>=0;i--){
            if(obstacleGrid[i][n-1]==0&&cnt[i+1][n-1]==1)cnt[i][n-1]=1;
            for(int j=n-2;j>=0;j--){
                if(obstacleGrid[i][j]==1)continue;
                cnt[i][j]=cnt[i][j+1]+cnt[i+1][j];
            }
        }
        return cnt[0][0];
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m=obstacleGrid.size();
        if(m==0)return 0;
        const int n=obstacleGrid[0].size();
        if(n==0||obstacleGrid.back().back()==1)return 0;
        
        vector<long long> dp(n,0);//不开long long还爆炸...
        
        //last level
        dp.back()=1;
        for(int i=n-2;i>=0;i--){
            if(dp[i+1]&&obstacleGrid[m-1][i]==0){
                dp[i]=1;
            }else break;
        }
        //
        // for(int j=0;j<n;j++)cout<<dp[j];
        //     cout<<'\n';
        
        for(int i=m-2;i>=0;i--){
            dp[n-1]=(obstacleGrid[i][n-1]==0&&dp[n-1]==1)?1:0;
            for(int j=n-2;j>=0;j--){
                // cout<<dp[j+1]<<' ';
                if(obstacleGrid[i][j]==1)dp[j]=0;
                else dp[j]=dp[j+1]+dp[j];
            }
            // for(int j=0;j<n;j++)cout<<dp[j];
            // cout<<'\n';
            // cout<<dp[0]<<'\n';
        }
        
        
        return dp[0];
    }
};