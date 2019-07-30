#include <algorithm>
#include <vector>

using namespace std;

class _Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> _nums = nums;
        sort(_nums.begin(), _nums.end());
        
        int start;
        for(start=0;start<nums.size()&&nums[start]==_nums[start];start++);
        if(start == nums.size())return 0;
        int end;        
        for(end=nums.size()-1;end>=0&&nums[end]==_nums[end];end--);
        
        return end - start+1;
    }
};


//需要扫描4次数组
//两次分别确定未排序子数组的最小值和最大值
//后两次通过这两个值来确定出错的位置

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()<2)return 0;
        //
        bool flag = false;
        int min_val = INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                flag = true;
            }
            if(flag){
                min_val = min(min_val, nums[i+1]);
            }
        }
        //
        flag = false;
        int max_val = INT_MIN;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                flag = true;
            }
            if(flag){
                max_val = max(max_val, nums[i-1]);
            }
        }
        //
        int start;
        for(start=0;start<nums.size();start++){
            if(nums[start]>min_val)break;
        }
        int end;
        for(end=nums.size()-1;end>=0;end--){
            if(nums[end]<max_val)break;
        }
        return start<end? end-start+1:0;
    }
};