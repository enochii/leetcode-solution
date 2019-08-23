#include <vector>
#include <algorithm>

using namespace std;

//就保留当前的最小数和
//已经有序的二元组
//并保持这个二元组的尾巴最小
//因为是三元组，所以状态比较小--
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        int mini=nums[0];
        int sec=INT_MAX;
        //
        for(int i=1;i<nums.size();i++){
            if(nums[i]>sec)return true;

            if(nums[i]>mini){
                if(nums[i]<sec){
                    sec=nums[i];
                }
            }else if(nums[i]<mini){
                mini=nums[i];
            }
        }
        return false;
    }
};