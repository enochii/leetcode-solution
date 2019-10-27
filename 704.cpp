// 704. Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m] < target){
                l = m+1;
            }else{
                r = m;
            }
        }
        return (l<nums.size()&&target == nums[l])? l:-1;
    }
};