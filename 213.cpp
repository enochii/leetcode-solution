// 213. House Robber II

#include <vector>
#include <utility>
#include <algorithm>

#include <iostream>

using namespace std;

//感觉这样的dp有问题，跳了
//不过算是知道?:这个运算符的优先级

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.empty())return 0;
//         if(nums.size()==1)return nums[0];

//         const int sz=nums.size();
//         vector<vector<int>> dp(sz,vector<int>(2));
//         vector<pair<bool,bool>> stolen_first(sz,{false,false});
//         //1表示要了，0表示不要
//         dp[0][0]=0,dp[0][1]=nums[0];
//         stolen_first[0].second=true;
//         for(int i=1;i<sz-1;i++){
//             if(dp[i-1][0]>=dp[i-1][1]){
//                 dp[i][0]=dp[i-1][0];
//                 stolen_first[i].first=stolen_first[i-1].first;
//             }else{
//                 dp[i][0]=dp[i-1][1];
//                 stolen_first[i].first=stolen_first[i-1].second;
//             }
//             if(dp[i-1][0]==dp[i-1][1]){
//                 stolen_first[i].first=stolen_first[i-1].first
//                     &&stolen_first[i-1].second;
//                 // cout<<stolen_first[i].first<<"???\n";
//             }
//             //
//             dp[i][1]=dp[i-1][0]+nums[i];
//             stolen_first[i].second=stolen_first[i-1].first;
//         }
//         dp.back()[0]=max(dp[sz-2][0],dp[sz-2][1]);
//         //该加括号就加括号...
//         //三目优先级比 + 低
//         dp.back()[1]=dp[sz-2][0]+(stolen_first[sz-2].first?0:nums.back());

//         for(int i=0;i<sz;i++){
//             cout<<stolen_first[i].first<<' '<<stolen_first[i].second<<'\n';
//             cout<<dp[i][0]<<' '<<dp[i][1]<<"\n\n";
//         }

//         return max(dp.back()[0],dp.back()[1]);
//     }
// };



class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);

        vector<int> dp(nums.size());
        return max(nums[0]+linear_rob(nums,2,nums.size()-1,dp),
            linear_rob(nums,1,nums.size(),dp)
        );
    }

    int linear_rob(vector<int>& nums, int l, int r,vector<int>& dp){
        if(l==r)return 0;
        if(r-l==1)return nums[l];
        //sz>=2
        dp[l]=nums[l],dp[l+1]=max(nums[l],nums[l+1]);
        for(int i=l+2;i<r;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[r-1];//注意sz==2的情况
    }
};

// int main(){
//     vector<int> xi{2,3,2};
//     cout<<Solution().rob(xi);

//     return 0;
// }
