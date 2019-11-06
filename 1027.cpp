// 1027. Longest Arithmetic Sequence
//dp

//O(n^3)
//6168 ms + 37.8 MB
class _Solution {
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        //dp[i][j]表示以i和j为结尾能达到的最大长度
        const int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //
                for(int k = 0;k<i;k++)
                {
                    if(A[k]+A[j] == 2 * A[i])
                    {
                        dp[i][j] = max(dp[k][i] + 1, dp[i][j]);
                    }
                }
                //
                ans = max(ans, dp[i][j]);
                // cout <<  dp[i][j] <<' ';
            }
            // cout<<'\n';
        }
        
        return ans+2;
    }
};

//O(n^2) (忽略哈希)

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        unordered_map<int, int> mp;
        const int n = A.size();
        
        // for(int i=0;i<n;i++)
        // {
        //     mp[A[i]] = i;
        // }
        //不太一样的是，只更新小的，所以可以从后往前更新
        //这样也不太对，不是下标小就好，还要考虑它已有的链条的长度
        // for(int i=n;i>0;i--)
        // {
        //     mp[A[i-1]] = i-1;
        // }
        
        //之前那道题元素互异并且递增就是有点爽嗷
        
        mp[A[0]] = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int exp = 2*A[i] - A[j];//expected
                auto it = mp.find(exp);
                if(it != mp.end() && it->second < i)
                {
                    dp[i][j] = max(dp[it->second][i]+1, dp[i][j]);
                }
                ans = max(ans, dp[i][j]);
            }
            mp[A[i]] = i;//选择在这里更新
        }
        return ans + 2;
    }
};