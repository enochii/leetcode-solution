// 1 <= d, f <= 30
// 1 <= target <= 1000

const int MOD_VAL = 1000000007;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        //dp[i][rolled] 表示已经用了 i 个骰子，且得分为 rolled 的方案数
        vector<vector<int>> dp(d+1, vector<int>(target+1, 0));
        
        dp[0][0] = 1;
        for(int i=1;i<=d;i++)
        {
            for(int rolled=i-1;rolled<target-(d-i);rolled++)
            {
                if(dp[i-1][rolled] == 0)continue;
                for(int cur=1;cur<=f;cur++)
                {
                    if(rolled+cur>target)break;
                    
                    dp[i][rolled+cur] += dp[i-1][rolled];
                    dp[i][rolled+cur] %= MOD_VAL;
                }
            }
        }
        
        return dp.back().back();
    }
};