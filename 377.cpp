#include <vector>
#include <algorithm>

using namespace std;

//几个COmbination Sum问题里面
//好像只有这个需要记忆化
//感觉起来其他几个不会有重复计算的问题
//而这个每次都要从0开始
class Solution {
public:
    // int ans;
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> mem(target+1,-1);
        mem[0]=1;
        // sort(nums.begin(),nums.end());
        return recur(nums,target,mem);
    }

    int recur(vector<int>& nums, int todo, vector<int>& mem){
        if(mem[todo]!=-1)return mem[todo];
        // if(todo==0){
        //     return 1;
        // }
        int ans=0;
        //前提：no duplicates
        //这里开始搜索的位置其实有点讲究
        //如果是元素可复用，那就从0开始
        //否则要从i开始
        //
        for(int i=0;i<nums.size();i++){
            if(todo<nums[i])continue;
            ans+=recur(nums,todo-nums[i],mem);
        }
        return mem[todo]=ans;
    }
};