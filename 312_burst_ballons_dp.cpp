#include <vector>
#include <algorithm>

using namespace std;

//dp 类似矩阵链乘
//然而我不会-=-
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //引入首尾两个气球
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(),0));
        // dp[i][i+1]=0 
        //dp[i][j]表示戳破i和j之间(不包括)的气球得到的最大分数
        for(int len=2;len<dp.size();len++){
            for(int i=0;i+len<dp.size();i++){
                int j=i+len;
                for(int k=i+1;k<j;k++){
                    //k是最后戳破的...有点6
                    int res = dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j];
                    dp[i][j]=max(dp[i][j],res);
                }
            }
        }
        return dp[0][dp.size()-1];
    }
};