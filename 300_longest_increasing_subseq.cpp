#include <vector>
#include <algorithm>

using namespace std;

//LIS，用dp解决，时间复杂度为O(n^2)

//还有一种O(nlogn)的解法，这个有点抽象
//就是维护一个单调递增的子序列is
//遍历原数组，在is中合适的位置插入(利用二分搜索加速)
//当设当前元素为e，只有e大于is.back()才会进行扩容
//子序列的最后一个元素(也即最大元素)标识了当前一个最大序列中最容易扩容的子序列

class _Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       vector<int> dp(nums.size(),1);
    //    dp[0] = 1;
       for(int i=1;i<nums.size();i++){
           for(int j=0;j<i;j++){
               if(nums[i]>nums[i]){
                   dp[i]=max(dp[j]+1,dp[i]);
               }
           }
       }
       return dp[dp.size()-1];
    }
};

class Solution{
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;

        for(auto num:nums){
            if(ans.empty()||num>ans.back()){
                ans.push_back(num);
            }else{
                ans[bsearch(ans, num)] = num;
            }
        }
        return ans.size();
    }

//ans是非空的
//找到第一个不比ele小的值的下标
    int bsearch(vector<int>& ans, int ele){
        int l=0,h=ans.size();
        while(l<h){
            int mid = (l+h)/2;
            // if(ans[mid]==ele)return mid;
            if(ans[mid]>=ele){
                h=mid;
            }else{
                l=mid+1;
            }
        }
        return h;
    }
};