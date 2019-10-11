// 713. Subarray Product Less Than K
//有点魔怔，还以为是dp...
//Two Pointer
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1 || nums.empty())return 0;
        const int n = nums.size();
                
        vector<int> dp(n, -1);
        long long pro = 1;
        int start = 0;
        int ans=0;
        for(int i=0;i<n;i++){
            pro *= nums[i];
            while(pro >= k){
                pro /= nums[start++];
            }
            //加上以自己为结尾的cnt
            ans += i-start+1;
        }
        return ans;
    }
};