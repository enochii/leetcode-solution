// 583. Delete Operation for Two Strings

class _Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size(), n = word2.size();
        if(m==0||n==0)return m+n;
        
        //dp[i][j]表示使得word1[0:i]和word2[0:j]匹配需要删除多少字符
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        
        for(int j=0;j<n;j++)dp[0][j+1] = j+1;//边界
        for(int i = 0;i<m;i++){
            dp[i+1][0] = i+1;//边界
            for(int j = 0;j<n;j++){
                if(word1[i] == word2[j]){
                    dp[i+1][j+1] = dp[i][j];
                }else{
                    dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j])+1;
                }
                // cout<<dp[i+1][j+1]<<' ';
            }
            // cout<<'\n';
        }
        return dp.back().back();
    }
};

//滚动数组
//注意状态转移方程，变量的值有没有被覆盖
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size(), n = word2.size();
        if(m==0||n==0)return m+n;
        
        vector<int> dp(n+1, 0);
        for(int j=0;j<n;j++){
            dp[j+1] = j+1;
        }
        for(int i=0;i<m;i++){
            int last = dp[0];
            dp[0] = i+1;
            for(int j=0;j<n;j++){
                int tmp = dp[j+1];
                if(word1[i] == word2[j]){
                    dp[j+1] = last;//这个last比较之关键
                }else{
                    dp[j+1] = 1+min(dp[j+1],dp[j]);
                }
                last = tmp;
            }
        }
        return dp.back();
    }
};