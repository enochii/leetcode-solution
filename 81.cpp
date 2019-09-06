#include <vector>
#include <algorithm>

using namespace std;

//31 的加强版
//就是加了可重复这个条件

//感觉这个想法其实有点万金油
//就是找到minimum，这个可以参考前面的
//然后其实两边就都是有序的了...

//Binary Search
//Rotated sorted array search
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //先找到最小值
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
        // cout<<l;
        //现在l==r并且nums[l]是最小值
        if(l==0){
            return bsearch(nums.begin(),nums.end(),target);
        }else if(target>nums.back()){
            return bsearch(nums.begin(),nums.begin()+l,target);
        }else{
            return bsearch(nums.begin()+l,nums.end(),target);
        }
    }

    typedef vector<int>::iterator it;
    bool bsearch(it beg, it end, int val){
        int l=0,r=end-beg;
        if(r==0)return false;
        while(l<r){
            int m=l+(r-l)/2;
            if(*(beg+m)>=val){
                r=m;
            }else{
                l=m+1;
            }
        }
        return l!=end-beg&&*(beg+l)==val;
    }
};