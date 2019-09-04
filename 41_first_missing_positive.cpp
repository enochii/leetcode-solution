#include <vector>

using namespace std;

//这个问题要求O(1)空间
//很容易想到那种变负的手法
//但由于原数组就存在负数，在某个点无法判断是你变负还是本来就是负数
//所以我们可以直接把负数移到后面
//相当于把原数组的负数全部筛掉，因为他们本来就是干扰项
//接下来就是取负工作了

//还有另一种标志的办法
//如果数组存在i+1，那么把它交换到nums[i]的位置上
//这样可以避开负数

class _Solution {
public:
    //把负数放在后面
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())return 1;
        int i=0,r=nums.size()-1;
        //
        while(i<=r){
            if(nums[i]<=0){
                swap(nums[i],nums[r--]);
            }else{
                i++;
            }
        }
        // for(int i=0;i<nums.size();i++){
        //     cout<<nums[i]<<' ';
        // }
        // cout<<r;
        r++;//这个是分界点(第一个负数)
        for(int i=0;i<r;i++){
            int num=abs(nums[i]);
            //我们不用管大于r的数原因是：如果存在，那么必有小于等于r的正数
            //的位置被挤掉了，不会轮到大于r的数
            if(num>r)continue;
            
            nums[num-1]=-abs(nums[num-1]);
        }
        //
        for(int i=0;i<r;i++){
            if(nums[i]>0)return i+1;
        }
        return r+1;
    }
};


//swap手法
//把i(0<i<=nums.size())放到nums[i-1]
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();){
            if(nums[i]>nums.size()||nums[i]<1
               ||nums[i]==i+1
              ||nums[nums[i]-1]==nums[i]){
                i++;
                continue;
            }
            // if(){
                swap(nums[i],nums[nums[i]-1]);
            // }
        }
        //
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)return i+1;
        }
        //
        return nums.size()+1;
    }
};