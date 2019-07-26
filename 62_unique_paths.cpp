#include<algorithm>

using namespace std;

//组合问题
//0 ms
//8.1 MB
class Solution {
public:
    int uniquePaths(int m, int n) {
        // C(m+n-2, n-1);
        return C(m+n-2, min(m-1,n-1));
    }
    
    int C(int m, int n){
        long long product = 1;
        for(int i=0;i<n;i++){
            product*=m-i;
        }
        for(int i=n;i>1;i--){
            product /= i;
        }
        
        return (int)product;
    }
};