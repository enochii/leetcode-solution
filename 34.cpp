#include <vector>

using namespace std;

//也就是要找到指定值的一个区间
//折半搜索的变形
//代码有点丑
//把除pred外的代码改一下比较DRY

//二分其实是比较常见的
//这里再分析一手基于if-else到死的二分
//我们称if的判断条件为pred
//事实上，我们总会到最后一种情况，也就是lo+1==hi
//这时候，如果mid即lo满足pred，那么hi=mid
//否则lo=mid+1
//最后lo=hi
//对于上面的两种情况都会有 lo不满足pred

//具体到这道题，你就可以找到第一个不小于
//和第一个大于(再做个-1)
//问题就不大了！

class Solution {
public:
//找到第一个不小于和最后一个不小于
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1,-1};
        //
        int lo=0,hi=nums.size();
        while(lo<hi){
            int mid=(hi+lo)/2;
            if(nums[mid]<target){//我们把这个成为pred
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        //事实上lo=hi && nums[lo]>=target
        //也就是找到第一个不满足pred的下标
        if(lo>=nums.size()||nums[lo]!=target)return{-1,-1};
        int beg=lo;
        lo=0,hi=nums.size();
        while(lo<hi){
            int mid=(hi+lo)/2;
            if(nums[mid]<=target){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        return{beg,lo-1};
    }
};