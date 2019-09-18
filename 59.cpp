//把上一道Spiral抄一抄就行(⊙﹏⊙)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int l=0,r=n-1,u=0,d=n-1;
        int cnt=0;
        while(l<=r&&u<=d){
            for(int i=l;i<=r;i++){
                ans[u][i]=++cnt;
            }
            u++;
            for(int i=u;i<=d;i++){
                ans[i][r]=++cnt;
            }
            r--;
            for(int i=r;i>=l;i--){
                ans[d][i]=++cnt;
            }
            d--;
            for(int i=d;i>=u;i--){
                ans[i][l]=++cnt;
            }
            l++;
        }
        return ans;
    }
};