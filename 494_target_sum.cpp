#include <vector>
#include <iostream>

using namespace std;

// typedef long long ll;
class _Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return(0, nums, S);//tmd，这都能返回一个值S
        int sum = 0;
        for(auto x:nums){
            sum+=x;
            if(x<0)return -1;
        }
        //记得加判断，因为S有可能很大而nums的和最多到1000
        //不加判断会导致溢出，因为下面的计算和是倒着来的...
        if(sum<S||sum<-S){
            return 0;
        }
        
        return recur(0, nums, S);
    }
    
    int recur(int i, vector<int>& nums, int leftS){
        if(i >= nums.size()){
            //数组为空,判断和是否符合条件
            return leftS == 0;
        }
        // cout<<"=";
        int r1 = recur(i+1, nums, leftS-nums[i]);//nums[i]为正数
        int r2 = recur(i+1,nums,leftS+nums[i]);//nums[i]为负数
        return r1+r2;
    }
};

//输出也能从28ms卡到TLE，长见识了...
class __Solution {
    bool vaild(int limit, int num){
        return num <= limit && num>=0;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return(0, nums, S);//tmd，这都能返回一个值S
        int sum = 0;
        // vector<int> sums=vector<int>(nums.size());
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            sum+=x;
            // sums[i] = sum;
            if(x<0)return -1;
        }
        
        if(sum<S||sum<-S){
            return 0;
        }

        //dp[i][j]表示前i个元素和为j的方法数
        // vector<vector<int>>  = 
        //     vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum+1,0));
        int dp[21][2001] = {0};
        dp[0][sum]=1;//sum是偏移量
        for(int i = 1;i<nums.size()+1;i++){
            for(int j = 0;j<2*sum+1;j++){
                // int r1 = (dp[i-1][j - nums[i]]==-1)?0:dp[i-1][j - nums[i]];
                // int r2 = (dp[i-1][j + nums[i]]==-1)?0:dp[i-1][j + nums[i]];
                int r1 = vaild(2*sum, j - nums[i-1])?
                 (dp[i-1][j - nums[i-1]]):0;
                 int r2 = vaild(2*sum, j + nums[i-1])?
                 (dp[i-1][j + nums[i-1]]):0;
                dp[i][j]=r1+r2;
                // cout<<dp[i][j];
            }
            // cout<<endl;
        }

        if(S<0){
            S=-S;
        }
        return dp[nums.size()][S+sum];
    }
};

class Solution {
    bool vaild(int limit, int num){
        return num <= limit && num>=0;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // return(0, nums, S);//tmd，这都能返回一个值S
        int sum = 0;
        // vector<int> sums=vector<int>(nums.size());
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            sum+=x;
            // sums[i] = sum;
            if(x<0)return -1;
        }
        
        if(1000<S||1000<-S){
            return 0;
        }

        //dp[i][j]表示前i个元素和为j的方法数
        // vector<vector<int>>  = 
        //     vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum+1,0));
        int dp[21][2001] = {0};
        if(sum>1001){
            return -1;
        }
        dp[0][1000]=1;//sum是偏移量
        for(int i = 1;i<nums.size()+1;i++){
            for(int j = 0;j<sum+1001;j++){
                // int r1 = (dp[i-1][j - nums[i]]==-1)?0:dp[i-1][j - nums[i]];
                // int r2 = (dp[i-1][j + nums[i]]==-1)?0:dp[i-1][j + nums[i]];
                int r1 = vaild(2000, j - nums[i-1])?
                 (dp[i-1][j - nums[i-1]]):0;
                 int r2 = vaild(2000, j + nums[i-1])?
                 (dp[i-1][j + nums[i-1]]):0;
                dp[i][j]=r1+r2;
                // cout<<dp[i][j];
            }
            // cout<<endl;
        }

        // if(S<0){
        //     S=-S;
        // }
        return dp[nums.size()][S+1000];
    }
};

int main(){
    Solution sln;
    vector<int> xi = {1,1,1,1,1};
    cout<<sln.findTargetSumWays(xi, 3);

    // cout<<"========";
    return 0;
}