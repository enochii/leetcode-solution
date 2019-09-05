#include <vector>

using namespace std;

//Minimum size subarray sum
//Sliding Window
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())return 0;
        int sum=0;
        int start=0, end=0;
        int min_len=-1;
        while(1){
            //找到符合条件
            for(;end<nums.size()&&sum<s;end++){
                sum+=nums[end];
            }
            
            //在死亡边缘尝试
            while(start<nums.size()&&sum-nums[start]>=s){
                sum-=nums[start++];
            }
            //
            if(sum>=s&&(min_len==-1||min_len>end-start)){
                min_len=end-start;
            }
            sum-=nums[start++];
            if(end==nums.size())break;
        }
        return min_len==-1?0:min_len;
    }
};