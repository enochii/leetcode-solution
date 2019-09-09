// 714. Best Time to Buy and Sell Stock with Transaction Fee

#include <vector>
#include <algorithm>

using namespace std;

//滚动 136ms 15MB
//无脑dp 220ms 50.9MB
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        //0表示无货存，1表示有
        // dp[0][1]=-prices[0];
        int yes=-prices[0],no=0;
        for(int i=1;i<prices.size();i++){
            // dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
            // dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
            int lastno=no,lastyes=yes;
            no=max(no,yes+prices[i]-fee);
            yes=max(lastyes,lastno-prices[i]);
        }
        // for(int i=0;i<prices.size();i++){
        //     cout<<dp[i][0]<<' '<<dp[i][1]<<'\n';
        // }
        
        // return dp[prices.size()-1][0];
        return no;
    }
};