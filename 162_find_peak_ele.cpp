#include <vector>

using namespace std;

//因为有两边是无穷大的限制(题目给的假设)
//我们可以想象，我们可以用二分对区间进行逼近
//由于相邻元素不相同，所以每次缩小范围时总可以找到一个更小的区间
//满足两端(包括一开始虚拟的两个元素)小于他们内侧的相邻点
//当区间缩到足够小就ok了

//这道题挺玄学的...有贼多个反对
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
};