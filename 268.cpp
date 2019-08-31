class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //除了miss的那个数，所有的数和下标刚好成双
        int miss=nums.size();
        for(int i=0;i<nums.size();i++){
            miss^=(i^nums[i]);
        }
        return miss;
    }
};