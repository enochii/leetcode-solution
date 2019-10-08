// 376. Wiggle Subsequence
//O(n) / O(n)

class _Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 1)return n;
        //dp[i][0/1]表示以i为结尾的最大length，0代表其处于峰，1表示处于低谷
        vector<vector<int>> dp(n, vector<int>(2, 1));
        
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }else if(nums[i] < nums[j]){
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        
        return ans;
    }
};

//greedy
// 1,17,5,10,13,15,10,5,16,8
//满足则+1，比如 1 17 5
//不满足则换数 5->10->13->15，让峰顶越来越高，对后续越来越有利
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 1)return n;
        
        int i = 1;
        while(i<n && nums[i] == nums[0])i++;
        if(i == n)return 1;
        bool up = nums[i] > nums[0];
        
        int cnt = 1;
        for(/**/;i<n;i++){
            if(up){
                if(nums[i] > nums[i-1]){
                    up = !up;
                    cnt++;
                }
            }else{
                if(nums[i] < nums[i-1]){
                    up = !up;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
        