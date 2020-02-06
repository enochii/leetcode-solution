// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         if(nums.empty()) return 0;
        
//         const int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(3, 0));
//         for(int i=n-1;i>=0;i--)
//         {
//             vector<int> tmp = dp[i+1];
//             for(int j=0;j<3;j++)
//             {
//                 int val = dp[i+1][j] + nums[i];
//                 // 可能是 i+1 的旧值，也可能是因为 i+1 中有 0
//                 // 就是说， 可能不要 nums[i]
//                 tmp[val % 3] = max(tmp[val%3], val);
//             }
//             // for(int val:tmp)
//             // {
//             //     cout << val << ' ';
//             // }
            
//             dp[i] = tmp;
//         }
        
//         return dp.front().front();
//     }
// };


//滚动起来 
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        const int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));
        bool flag = 0;
        for(int i=n-1;i>=0;i--)
        {
            dp[flag] = dp[!flag];
            for(int j=0;j<3;j++)
            {
                int val = dp[!flag][j] + nums[i];
                // 可能是 i+1 的旧值，也可能是因为 i+1 中有 0
                // 就是说， 可能不要 nums[i]
                dp[flag][val % 3] = max(dp[flag][val%3], val);
            }
            // for(int val:tmp)
            // {
            //     cout << val << ' ';
            // }
            flag = !flag;
        }
        
        return dp[!flag].front();
    }
};