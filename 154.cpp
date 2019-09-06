#include <vector>

using namespace std;

class _Solution {
public:
    int findMin(vector<int>& nums) {
        //参考153
        //如果我们拿末尾元素当基准元素的话
        //那么就需要避免最小元素的两边都存在与基准元素相等的元素
        int l=0,r=nums.size();
        while(l<r-1&&nums[l]==nums.back()){
            l++;
        }
        //后面就不会出现这种情况了
        while(l<r){
            // cout<<l<<' '<<r<<'\n';
            int mid=l+(r-l)/2;
            if(nums[mid]<=nums.back()){//记得是和back比较，找到第一个<=back()的数
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return nums[l];
    }
};

//放弃
// class Solution{
// public:
//     int findMin(vector<int>& nums) {
//         int l=0,r=nums.size()-1;
//         while(l<r){
//             int mid=(l+r)/2;
//             //注意这里的r和上面的back()...
//             if(nums[mid]>nums[r]){
//                 l=mid+1;
//             }else if(nums[mid]<nums[r]){
//                 r=mid;
//             }else{
//                 //这种情况只会出现在 末尾和起始[l,r]有相同的元素
//                 r--;//有点强...
//             }
//         }
//         //找到第一个mid 满足nums[mid]<nums[mid+1]
//         return nums[l];
//     }
// };