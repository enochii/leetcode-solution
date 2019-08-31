#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    
public:
    void wiggleSort(vector<int>& nums) {
        const int sz=nums.size();

        nth_element(nums.begin(), nums.begin()+sz/2, nums.end());
        int l=0, r=sz-1;
        auto f=[&sz](int index){return (index*2+1)%(sz|1);};
        //[mid, end] -> <= mid
        //[beg, mid) -> > mid
        int mid=*(nums.begin()+sz/2);
        //目标： 让偶数下标的nums[i] <= mid
        //        奇数下标的nums[i] >  mid
        //[mid, end]对应偶数下标
        //[beg, mid)对应奇数下标
        int i=0;
        
        while(i<=r){
            if(nums[f(i)]>mid){
                swap(nums[f(i)], nums[f(l)]);
                i++;//原地swap或者换过来一个mid
                l++;
            }else if(nums[f(i)]<mid){
                swap(nums[f(i)],nums[f(r)]);
                r--;
            }else{
                i++;
            }
        }
        //到了这里，我们排完了序
        //以未做f映射前的坐标为准
        //我们应该可以得到
        // 小于mid的数 |  ...mid... | 大于mid的数
    }
};