#include <vector>

using namespace std;

class _Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> have(nums.size(), false);
        for(auto i:nums){
            have[i-1] = true;
        }
        vector<int> res;
        for(int i=0;i<have.size();i++){
            if(!have[i]){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

//有点秀，用原数组的正负来判断是否存在某个数
class Solution{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int num:nums){
            int index = abs(num) - 1;
            nums[index] = -abs(nums[index]);
        }

        vector<int> res;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>0){
                res.push_back(i+1);
            }
        }
        return res;
    }
};