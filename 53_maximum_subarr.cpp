#include <vector>
#include <algorithm>

using namespace std;

//注意是连续的,我们用mem[i]表示nums[0:i]包含nums[i]的最大连续和
//所以可以直接转移方程:mem[i]=max(mem[i-1],0)+nums[i];
//注意到可以用滚动的思想做空间优化
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        // vector<int> mem(nums.size(), 1);

        int last=nums[0];
        int msum = nums[0];
        for(int i=1;i<nums.size();i++){
            last=max(last,0)+nums[i];
            msum=max(msum,last);
        }

        return msum;
    }
};