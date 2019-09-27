// 413. Arithmetic Slices
// DP 1D

class _Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int > start(A.size(), -1);
        //start[i] -> 从start[i]到i是一个slide
        for(int i=1;i<A.size();i++){
            start[i] = i-1;
        }
        
        int ans=0;
        for(int i=2;i<A.size();i++){
            if(A[i]+A[i-2] == A[i-1]*2)start[i] = start[i-1];
            ans += i - start[i]- 1;
        }
        
        return ans;
    }
};

class Solution{
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int psta = 0;
        
        int ans = 0;
        for(int i=2;i<A.size();i++){
            int start = i-1;
            if(A[i]+A[i-2] == A[i-1]*2){
                start = psta;
            }
            ans += i - start -1;
            psta = start;
        }
        
        return ans;
    }
};
    