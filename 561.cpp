// 561. Array Partition I
//要取到尽可能大的数，也就意味着要把小的放在一起
//这样可以减少取到小数字的频率
//排序后取奇数索引的数就行
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        
        int ret = 0;
        for(int i = 0;i<n;i++)
        {
            ret+= nums[i*2];
        }
        
        return ret;
    }
};