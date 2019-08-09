#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//partition...
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find_kth(0, nums.size(), nums, k);
    }
    int find_kth(int beg, int end, vector<int>& nums, int k){
        int pivot=nums[beg];
        int lo=beg+1,hi=end;
        while(lo<hi){
            if(nums[lo]>=pivot){
                lo++;
            }else{
                --hi;
                swap(nums[hi],nums[lo]);
            }
        }
        // if(lo!=end){
            nums[beg]=nums[lo-1];
        // }

        //分完 lo-1位置刚好可以放上pivot(没有必要实际放上去...)
        //前面大于等于pivot，后面小于pivot

        // nums[lo]=pivot;
        if(lo-beg==k){
            return pivot;
        }
        //
        if(lo-beg<k){
            return find_kth(lo, end, nums,k-(lo-beg));
        }else{
            // if(lo==end){
            //     return find_kth(beg+1,lo,nums,k);
            // }
            //那种边角情况，也就是pivot是最小元素也是可以处理的...
            //少了个if像是快了不少
            return find_kth(beg, lo-1, nums, k);
        }
    }
};

class __Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto lo=nums.begin(),hi=nums.end();
        while(lo<hi){
            int tmp=*lo;
            auto xi = partition(lo,hi,[tmp](int i){return i>tmp;});
            int dis=xi-lo+1;
            if(dis==k){
                return tmp;
            }
            if(dis==1){
                lo=lo+1;
                k--;
            }else if(dis<k){
                lo=xi;
                k-=dis-1;
            }else{
                hi=xi;
            }
        }
        return -1;
    }
};

class _Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find_kth(nums.begin(),nums.end(),k);
    }
    typedef vector<int>::iterator It;
    int find_kth(It first, It last,int k){
        // cout<<"!";
        int tmp=*first;//test
        auto xi = partition(first,last,[tmp](int i){return i>tmp;});
        // if(*xi!=tmp)cout<<'!';//test

        int dis = xi-first+1;
        if(dis==k){
            return tmp;
        }
        //第一个数是最大数且k!=1需要特殊判断
        if(dis==1){
            return find_kth(first+1,last,k-1);
        }
        if(dis<k){
            return find_kth(xi,last,k-dis+1);
        }else{
            return find_kth(first,xi,k);
        }
    }
};

// int main(){
//     vector<int> xi={3,2,1,5,6,4,};
//     // cout<<"!";    
//     cout<<Solution().findKthLargest(xi,2);
//     // cout<<"!";
//     return 0;
// }