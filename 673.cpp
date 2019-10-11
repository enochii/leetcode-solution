// 673. Number of Longest Increasing Subsequence
//在算Longest Length的同时更新cnt。有点牛逼
//DP
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if(n < 2)return n;
        
        int len = 1;
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    // dp[i] = max(dp[i], dp[j]+1);
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j]+1){
                        cnt[i] += cnt[j];
                    }
                }
            }
            len = max(len, dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i] == len)ans += cnt[i];
        }
        //长度
        return ans;
        
    }
};