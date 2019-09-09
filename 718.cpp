
// 718. Maximum Length of Repeated Subarray
#include <vector>
#include <algorithm>

using namespace std;

//滚动有时候还需要记录之前的值嗷嗷
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //DP问题
        //记dp[i][j]为以i和j开始相同的连续字符串最大长度
        //A[i]!=B[j], dp[i][j]=0
        //else        dp[i][j]=1+dp[i+1][j+1]
        const int asz=A.size(),bsz=B.size();
        vector<int> dp(bsz+1,0);
        // vector<vector<int>> ddp(asz+1,vector<int>(bsz+1,0));
        //最后一行已经初始化

        int ans=0;
        
        for(int i=asz-1;i>=0;i--){
            int last=dp[bsz];
            dp[bsz]=0;
            // ddp[i][bsz]=0;
            
            for(int j=bsz-1;j>=0;j--){
                int tmp=dp[j];                
                if(A[i]!=B[j]){
                    // ans=max(ans,dp[j]);
                    dp[j]=0;
                    // ans=max(ans,ddp[i][j+1]);
                    // ddp[i][j]=0;
                }
                else{
                    // ddp[i][j]=ddp[i+1][j+1]+1;
                    // ans=max(ddp[i][j],ans);
                    dp[j]=last+1;
                    ans=max(dp[j],ans);
                }
                last=tmp;
            }
        }
        return ans;
    }
};