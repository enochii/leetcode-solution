#include <vector>
#include <algorithm>

using namespace std;

//找零钱
//迭代好像要比递归快很多,哭唧唧
class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]&&dp[i-coins[j]]<dp[i]-1){
                    dp[i]=dp[i-coins[j]]+1;
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};

class _Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> mem(amount, INT_MAX);

        return coinChange_(coins, amount, mem);
    }

private:
    int coinChange_(const vector<int>& coins, int amount, vector<int>& mem){
        if(amount==0)return 0;

        // int ans=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount<coins[i])break;
            int xi = coinChange_(coins, amount-coins[i],mem);
            if(xi!=-1){
                mem[amount-1]=xi+1;
            }
        }
        if(mem[amount-1]==INT_MAX){
            mem[amount-1]=-1;
        }
        return mem[amount-1];
    }
};