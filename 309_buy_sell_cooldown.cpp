#include <vector>
#include <algorithm>

using namespace std;

//dp题...
//有三个状态
//0 -> 可售出
//1 -> 可购买
//2 -> cooldown
//状态转换
// 0和1状态都可以停留无动作
// 0 -售出-> 2, 2 - -> 1, 1 - 购买 -> 0

//应该是可以滚动数组优化一手的--
class _Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size()));
        
        dp[0][0]=-prices[0];
        dp[1][0]=0;
        dp[2][0]=INT_MIN;
        //
        for(int i=1;i<prices.size();i++){
            dp[0][i]=max(dp[0][i-1],dp[1][i-1]-prices[i]);
            dp[1][i]=max(dp[1][i-1],dp[2][i-1]);
            dp[2][i]=dp[0][i-1]+prices[i];
        }
        return max(dp[1][prices.size()-1], dp[2][prices.size()-1]);
    }
};

//空间优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        
        
        int sell = -prices[0];//可售出
        int purchase = 0;//可购买
        int cooldown = INT_MIN;//cooldown
        //
        for(int i=1;i<prices.size();i++){
            int t0=sell,t1=purchase,t2=cooldown;
            sell=max(t0,t1-prices[i]);
            purchase=max(t1,t2);
            cooldown=t0+prices[i];
        }
        return max(purchase,cooldown);
    }
};