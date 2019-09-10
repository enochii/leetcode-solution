// 188. Best Time to Buy and Sell Stock IV

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // vector<vector<int>> dp(k+1,vector<int>(prices.size(),0));
        //dp[i][j]表示到第j天(inclusive)且最多经历k次交易获得的最大利润
        //dp[i][j]=max(dp[i][j-1],dp[i-1][jj]+(prices[j]-prices[jj])) 0<=jj<j
        //dp[0][xx]已经全部初始化,没有交易就没有利润
        if(prices.size()<2)return 0;
        
        //这个时候相当于k的限制没用了，直接贪心
        if(k>prices.size()/2){
            int ret=0;
            for(int i=1;i<prices.size();i++){
                ret+=max(0,prices[i]-prices[i-1]);
            }
            return ret;
        }
        // k=min(k,(int)prices.size()/2);

        vector<int> ddp(prices.size(),0);

        for(int i=1;i<=k;i++){
            // dp[i][0]=0; //只有一天,停止交易
            // int tmp=dp[i-1][0]-prices[0];
            int tmp=ddp[0]-prices[0];
            for(int j=1;j<prices.size();j++){
                int ntmp=max(tmp,ddp[j]-prices[j]);
                ddp[j]=max(ddp[j-1],tmp+prices[j]);
                tmp=ntmp;
                // dp[i][j]=max(dp[i][j-1],tmp+prices[j]);
                // tmp=max(tmp,dp[i-1][j]-prices[j]);
            }
        }
        return ddp[prices.size()-1];
    }
};