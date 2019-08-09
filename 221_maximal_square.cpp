#include <vector>
#include <algorithm>

using namespace std;

//tmd 又是dp
//dp[i][j]表示以matrix[i-1][j-1]为右下角的最大长度矩阵
//dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
//画个图就知道了... 有点妙
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m=matrix.size();
        const int n=m?matrix[0].size():0;
        if(m||n)return 0;
        //多出来的一行一列用来做边界处理...
        vector<vector<int>> dp(matrix.size()+1, 
                                vector<int>(matrix.size()+1,0));
        int ans=0;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(matrix[i-1][j-1]=='0')dp[i][j]=0;
                else{
                    dp[i][j]=min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;    
    }
};