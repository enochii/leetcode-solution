#include <vector>

using namespace std;

//环形链表
//把数组元素看成下标，整个/部分数组会组成一个环形链表
//参考 LeetCode 142的分析
//虽然重复数可能出现超过两次，但是不会影响环形链表的组成...
class Solution {
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
    }
};