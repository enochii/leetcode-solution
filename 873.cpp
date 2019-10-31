// 873. Length of Longest Fibonacci Subsequence
class Solution {
    //严格单调递增
public:
    int lenLongestFibSubseq(vector<int>& A) {
        const int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        //这个状态表示比较之关键
        //dp[i][j]表示以A[i]和A[j]作为最后两个数  能达到的最大长度
        
        //O(n^3)会超时
        //搞一个hashMap，用类似two sum的做法
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[A[i]] = i;
        }
        
        int ans = 0;
        for(int i = 1;i<n;i++){
            for(int j=i+1;j<n;j++){
                //
                // for(int k = 0;k<i;k++){
                //     if(A[k]+A[i] == A[j]){
                //         dp[i][j] = max(dp[i][j], dp[k][i]+1);
                //     }
                // }
                auto it = mp.find(A[j]-A[i]);
                if(it!=mp.end() && it->second < i){
                    dp[i][j] = max(dp[i][j], dp[it->second][i]+1);
                }
                //
                ans = max(ans, dp[i][j]);
            }
        }
        return ans?ans+2:ans;
    }
    
    //看到一种比较牛逼的写法
    //就是不用hash，把三层循环的内循环变成了一层
    //双指针
    //这种手法一般都是用在有序并且i j k不相同的情况

    int lenLongestFibSubseqNB(vector<int>& A) {
        //dp[i][k]
        
        if(A.size() <= 2) return 0;
        //dp[i][j] max subsequence end with A[i],A[j];
        vector<vector<int> >dp(A.size(),vector<int>(A.size(),1));
        
        int ret = 0;
        for(int i = 2;i < A.size();i ++){
            int l = 0;
            int r = i-1;
            while(l < r){
                int sum = A[l] + A[r];
                // cout << sum << endl;
                // dp[r][i] = 1;
                if(sum < A[i]){
                    l ++;
                }else if (sum > A[i]){
                    r --;
                }else{
                    dp[r][i] = max(1,dp[l][r]+1);
                    // cout <<  dp[r][i] << endl;
                    ret = max(dp[r][i],ret);
                    l ++;
                    r --;
                }
            }
        }
        if(ret < 2) return 0;
        return ret+1;
    }
};

