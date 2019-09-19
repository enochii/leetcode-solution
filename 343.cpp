class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        vector<int> dp(n,0);
        dp[1]=2;dp[2]=3;
        for(int nn=3;nn<n;nn++){
            for(int split=2;split<=(nn+1)/2;split++){
                dp[nn]=max(dp[nn],dp[split-1]*dp[nn-split]);
            }
            // cout<<dp[nn]<<' ';
        }
        return dp.back();
    }
};
//算法的作业
//把2和3拎出来
//就是一个dp问题
//可以滚动优化下
//我记得还有一个疯狂拆3的版本