#include <algorithm>
#include <vector>

using namespace std;

// class Solution {
// //找一个子集就ok，应该是偶数的--
// //并且购买价格必小于卖出价格
// //否则我们总可以找到一个子集，删去亏损买卖来获得更高利润
// public:
//     int maxProfit(vector<int>& prices) {
//         if(prices.empty())return 0;
//         int sum = 0;
//         bool flag = true;//下一次是购买
//         vector<vector<int>> dp(2,vector<int>(prices.size()));
//         //
//         dp[0][0]=-prices[0];
//         dp[1][0]=0;
//         for(int i=1;i<prices.size();i++){
//             dp[1][i]=max(dp[1][i-1], dp[0][i-1]+prices[i]);
//             dp[0][i]=max(dp[0][i-1],dp[1][i-1]-prices[i]);
//         }
//         return dp[1][prices.size()-1];
//     }
// };

//艹 我在想啥 只能一次买卖
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int ans=0;
        int min_ = prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min_ && prices[i]-min_>ans){
                ans=prices[i]-min_;
            }
            min_=min(min_, prices[i]);
        }
        return ans;
    }
};