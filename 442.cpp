class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //我感觉标注负数就可以料
        vector<int> ans;
        for(int num:nums){
            int index = abs(num)-1;
            if(nums[index]<0)ans.push_back(abs(num));
            else{
                nums[index]=-nums[index];
            }
        }
        return ans;
        //一样的套路
        //第一次标注负数，第二次直接拘留
    }
};