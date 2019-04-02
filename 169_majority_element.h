class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int major_ele = nums[0];
        
        for(int i=0;i<nums.size();++i){
            if(major_ele!=nums[i]){
                if(--cnt<=0){
                    cnt=1;
                    major_ele=nums[i];
                }
            }else{
                ++cnt;
            }
        }
        return major_ele;
    }
};