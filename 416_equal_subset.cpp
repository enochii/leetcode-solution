#include <vector>
#include <algorithm>

using namespace std;

//两种方法
//动态规划：dp[i][j]代表从i开始是否能生成子集和为j
//dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]
//时间复杂度O(s*nums.size())，其中s为nums的和
//124 ms 8.5 MB

//回溯法生成子集(非重复)
//重复子集可以直接爆炸的...最后一个case好像是很多个1
//这东西思路有点意思
//4 ms 8.3 MB

//时间复杂度事实上取决于数据分布
//像那种和小数组大对dp稍微有利一点

//共同思路是判断总和是否是偶数，除以二就得到我们要的目标和
//dp的思路比较简单，不表(虽然我想不出来...)

//回溯法生成非重复子集的key在于
//先对数组做排序预处理
//当一个子集有多个重复的数时，我们只拿数组前面的若干重复数，这样就避免生成重复子集
//具体是在回溯法生成子集时记录一个last_index，在采纳一个数进入子集时判断即可，具体看代码吧

class _Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2){
            return false;
        }
        //
        int target = sum/2;
        sort(nums.begin(), nums.end());
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int i=0;i<nums.size();i++){
            for(int j=target;j>0;j--){
                //用上一轮小于等于j的结果，反向遍历
                if(j>=nums[i]&&dp[j-nums[i]]){
                    dp[j] = true;
                }
            }
        }
        return dp[target];
        
        // return partition(nums, 0,0,target);
    }

    // bool partition(vector<int>& nums, int cur, int sum, const int target){
    //     if(sum==target)return true;
    //     if(cur == nums.size())return false;

    //     return partition(nums,cur+1,sum+nums[cur],target)||
    //             partition(nums,cur+1,sum,target);
    // }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums){
            sum+=num;
        }
        if(sum%2){
            return false;
        }
        //
        int target = sum/2;
        sort(nums.begin(), nums.end());
        
        return subset_sum(nums,0,0,target,-1);
    }

    bool subset_sum(vector<int>& nums, int cur, int sum, const int target, int last_index){
        if(cur>=nums.size()){
            return false;
        }
        if(sum>target){//太大了，剪枝
            return false;
        }
        if(sum+nums[cur]==target){//结束
            return true;
        }
        //
        bool flag = false;
        //如果上一个数跟自己一样并且上一个数没被选中，当前数就不要进入子集，避免重复
        //比如[] [1] [2] [1,2] 然后再来一个2，明显只能多[2,2] [1,2,2]
        //这就是前面说的，如果取n个重复数，只取数组(已排序)中靠前的n个重复数
        if(!(cur>0&&nums[cur-1]==nums[cur]&&last_index!=cur-1)){
            flag = subset_sum(nums,cur+1,sum+nums[cur],target,cur);
        }
        return flag || subset_sum(nums, cur+1,sum,target,last_index);

    }
};