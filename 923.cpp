// 923. 3Sum With Multiplicity

// Two Pointer
//注意一些边界条件
//预排序
// 1 2 2 3 3 类似这种 求6
// 1 2 2 2 2 求5
//记得取余嗷 不然long long 也没用--
const int LIMIT = 1000000007;
class Solution {
    
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int sz=A.size();
        sort(A.begin(),A.end());
        
        int ans=0;
        for(int i=0;i<sz;i++){
            int l=i+1;
            int r=sz-1;
            //i<l<r !
            while(l<r){
                int sum=A[i]+A[l]+A[r];
                if(sum==target){
                    if(A[l]==A[r]){
                        int n=r-l+1;
                        ans+=n*(n-1)/2;
                        break;
                    }
                    int oldl=l++;
                    while(l<r&&A[l]==A[oldl])l++;
                    
                    int oldr=r--;
                    while(l<=r&&A[r]==A[oldr])r--;
                    
                    // cout<<oldl<<' '<<l<<' '<<oldr<<' '<<r<<'\n';
                    ans+=(l-oldl)*(oldr-r);
                }
                else if(sum>target){
                    r--;
                }else{
                    l++;
                }
            }
            if(ans>LIMIT)ans%=LIMIT;
        }
        
        return ans;
    }
};