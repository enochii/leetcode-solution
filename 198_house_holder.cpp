#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class _Solution {
    vector<int> mem;
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        mem.assign(nums.size(), -1);
        
        
        recur(nums, 0);
        return mem[0];
    }
    
    //返回从下标pos开始之后能rob到的最大金额
    int recur(vector<int>& nums, int pos){
        if(pos >= nums.size()){
            return 0;
        }
        // if(pos == nums.size()-1){
        //     return nums.back();
        // }
        if(mem[pos]!=-1){
            return mem[pos];
        }
        
        return mem[pos] = max(nums[pos]+recur(nums, pos+2), recur(nums,pos+1));
    }
};

class Solution{
    vector<int> mem;
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        
        mem.assign(nums.size(), -1);
        
        int before2, before3;
        // int max_money;
        
        int i=0;
        for(i=0;i<nums.size();i++){
            before2 = i-2>=0? mem[i-2]:0;
            before3 = i-3>=0? mem[i-3]:0;

            mem[i] = nums[i] + max(before2, before3);
        }
        return max(mem[i-1],mem[i-2]);
    }
};