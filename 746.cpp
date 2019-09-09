// 746. Min Cost Climbing Stairs
//Easy / Fib / DP
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty())return 0;
        if(cost.size()==1)return cost[0];
        vector<int> dp(cost.size()+1);
        dp.back()=0;
        dp[cost.size()-1]=cost.back();
        for(int i=dp.size()-3;i>=0;i--){
            dp[i]=min(dp[i+1],dp[i+2])+cost[i];
        }
        return min(dp[0],dp[1]);
    }
};