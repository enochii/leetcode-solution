class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        //
        int cur=nums[0];
        int cnt=1;
        //
        for(int num:nums){
            if(cur==num)continue;
            
            cur=num;
            if(++cnt==3)break;
        }
        return cnt==3?cur:nums[0];
    }
};