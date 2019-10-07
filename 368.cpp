// 368. Largest Divisible Subset
//DP

//如果dp[i]表示nums[i]的因子，那么对于nums[j] % nums[i] == 0，我们有dp[j] = dp[i] + nums[j]
//我们在dp的过程中不构造结果数组，只是记录对应的上个下标，比如last[j] = i
//在得到最大长度对应的下标后，反推就可以得到结果了
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //不是并查集？ 比如 2 3 6
        const int n = nums.size();
        if(n == 0)return {};
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> last(n, -1);
        
        int cnt = 1;
        int index = 0;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                    last[i] = j;
                    if(dp[i] > cnt){
                        cnt = dp[i];
                        index = i;
                    }
                }
            }
        }
        
        vector<int> ans;
        while(index != -1){
            ans.push_back(nums[index]);
            index = last[index];
        }
        return ans;
    }
};