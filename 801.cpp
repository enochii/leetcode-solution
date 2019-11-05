// 801. Minimum Swaps To Make Sequences Increasing
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        
        //次数必定小于 n / 2
        //因为对于某个转换，必定会有一个互补的转换
        //min(cnt,n - cnt)
        //贪心不太行
        
        //另一种想法
        
        int cnt = 0;
        
        //事实上可以做成滚动数组
        vector<vector<int> > dp(n, vector<int>(2));
        dp[0] = {0,1};
        
        for(int i=1;i<n;i++){
            //不得不换
            if(A[i] <= A[i-1] || B[i] <= B[i-1]){
                dp[i][0] = dp[i-1][1];//换别人
                dp[i][1] = dp[i-1][0]+1;//换自己
            }else{
                //没必要换
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1] + 1;
                
                //但是可以换
                if(A[i] > B[i-1] && B[i] > A[i-1]){
                    dp[i][0] = min(dp[i][0], dp[i-1][1]);
                    dp[i][1] = min(dp[i][1], dp[i-1][0]+1);
                }
            }
        }
        
        return min(dp.back()[0], dp.back()[1]);
    }
};