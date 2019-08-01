#include <vector>

using namespace std;

//变形的折半搜索
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size();
        while(low<high){
            int mid = (low+high)/2;
            if(target == nums[mid]){
                return mid;
            }else if(nums[low]<nums[mid]&&(nums[low]<=target&&nums[mid]>target)
            || nums[low]>nums[mid]&&(target>=nums[low]||target<nums[mid])
            ){
                high = mid;
            }else{
                low = mid+1;
            }
        }

        return -1;
    }
};