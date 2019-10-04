// 983. Minimum Cost For Tickets
//DP

//感觉有点天数像背包，但是天数的选择可以是多样的
//dp的状态要从天数来，分为从按365和days.size()两种递归
//dp[i]表示从第days[i]天到最后该年花的最小费用
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int n = days.size();
        if(n == 0)return 0;
        
        vector<int> dp(n, 0);
        
        //tmd，costs[0]不一定是最小的
        dp.back() = *min_element(costs.begin(),costs.end());
        for(int i=n-2;i>=0;i--){
            dp[i] = costs[0] + dp[i+1];
            
            int j;
            for(j=1;j+i<n && days[i+j] < 7+days[i];j++);
            dp[i] = min(dp[i], (i+j==n?0:dp[i+j]) + costs[1]);
            
            for(    ;j+i<n && days[i+j] < 30+days[i];j++);
            dp[i] = min(dp[i], (i+j==n?0:dp[i+j]) + costs[2]);
            // if(days[i] == 4)cout<<dp[i]<<" "<<i+j;
        }
        
        return dp[0];
    }
};