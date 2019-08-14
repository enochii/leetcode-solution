#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m=word1.size();
        const int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));

        for(int i=1;i<m+1;i++)dp[i][0]=i;
        for(int i=1;i<n+1;i++)dp[0][i]=i;
        dp[0][0]=0;
        //
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    //删除/插入/修改，只讨论i
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[m][n];
    }
};