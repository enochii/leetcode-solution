#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

//环形链表
//把数组元素看成下标，整个/部分数组会组成一个环形链表
//参考 LeetCode 142的分析
//虽然重复数可能出现超过两次，但是不会影响环形链表的组成...
class _Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[slow];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        //
        slow=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        //现在slow和fast刚好是指向线圈交汇点的指针也就是下标那就是重复数了！
        return slow;
    }
};
//
class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
        //nums中有n+1个数
        //假设重复数是k，那么对于大于等于k的数i，nums数组中小于等于i的数会大于i
        //小于k的数j，nums数组中小于等于j的数会小于等于j
        //上述结论只要想想重复数是替换哪些数就ok的

        //那么我们用二分的想法也就是找到数num，它满足条件
        //nums数组中，第一个小于等于num的数的count大于num本身
        int left=1,right=nums.size();//n+1
        while(left<right){
            int mid= (left+right)/2;
            if(count_dup(nums,mid)<=mid){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        //如果拿到n+1证明没有重复数，然而在这道题不会有这个情况
        return left;
    }
private:
    int count_dup(const vector<int>& nums, int num){
        int xi=0;
        for(int n:nums){
            xi+=(n<=num);
        }
        return xi;
    }
};

int main(){
    cout<<"287!!!\n";
    //做那种不可能的测试哈哈，因为n+1个数都在1-n里面，只是想证明自己没被打脸
    assert(Solution().findDuplicate({1,2,3,4,100000})==5);
    // cout<<Solution().findDuplicate({1,2,3,4})<<'\n';
    return 0;
}