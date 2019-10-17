
class Solution {
    using ht = unordered_set<int>;
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        // 501 * 500 < INT_MAX
        vector<vector<int>> dp(N,vector<int>(N));
        ht zeros;
        for(vector<int> & grid : mines){
            zeros.insert(grid[0] * N + grid[1]);
        }
        
        
        int cnt;
        for(int i=0;i<N;i++){
            cnt = 0;
            // >>>>>>>>
            for(int j=0;j<N;j++){
                // if(zeros.count(i*N+j)) cnt = 0;
                cnt = zeros.count(i*N+j)?0:cnt+1;
                dp[i][j] = cnt;
            }
            //<<<<<<
            cnt = 0;
            for(int j=N-1;j>=0;j--){
                cnt = zeros.count(i*N+j)?0:cnt+1;
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        //
        int ans=0;
        for(int j=0;j<N;j++){
            cnt=0;
            for(int i=0;i<N;i++){
                cnt = zeros.count(i*N+j)?0:cnt+1;
                dp[i][j] = min(dp[i][j], cnt);
            }
            cnt=0;
            for(int i=N-1;i>=0;i--){
                cnt = zeros.count(i*N+j)?0:cnt+1;
                dp[i][j] = min(dp[i][j], cnt);
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    
};

// class Solution {
//     using ht = unordered_set<int>;
// public:
//     int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
//         // 501 * 500 < INT_MAX
//         ht zeros;
//         for(vector<int> & grid : mines){
//             zeros.insert(grid[0] * N + grid[1]);
//         }
        
//         int ans =0;
//         for(int i=0;i<N;i++){
//             for(int j=0;j<N;j++){
//                 ans = max(ans, calculate(zeros, i, j,N));
//             }
//         }
//         return ans;
//     }
    
//     int calculate(ht &zeros, int x, int y, const int N){
//         int cnt = 0;
//         if(zeros.count(x*N+y))return 0;
        
//         ++cnt;
//         int u = x, d = x, l = y, r = y;
        
//         while(true){
//             if(--u < 0 || zeros.count(u*N+y))return cnt;
//             if(--l < 0 || zeros.count(x*N+l))return cnt;
//             if(++d >= N || zeros.count(d*N+y))return cnt;
//             if(++r >= N || zeros.count(x*N+r))return cnt;
            
//             cnt++;
//         }
//     }
// };