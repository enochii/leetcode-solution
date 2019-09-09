class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // nums.push_back(0);
        int cnt=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                cnt++;
            }else{
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return max(ans,cnt);
    }
};