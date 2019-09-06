//find minimum in rotated sorted array
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int> nums) {
        //找到符合 pre < min < next的数就ok
        //binary search ?
        const int sz=nums.size();
        int l=0,r=sz;
        auto fl=[&sz](int i){return i==0?sz-1:i-1;};
        auto fr=[&sz](int i){return i==sz-1?0:i+1;};
        while(l<r){
            int mid=(l+r)/2;
            // if(nums[mid]<nums[fl(mid)]){
            //     //小于左边的数
            //     return nums[mid];
            // }else{
                //跟最后一个数比较，可以通过大小判断是在min的前or后
                //5 6 0 1 2 3 4
                if(nums[mid]<=nums[sz-1]){
                    r=mid;
                }else{
                    l=mid+1;
                }
            // }
        }
        return nums[l];
    }
};

int main(){
    cout<<Solution().findMin({3,1});
    return 0;
}