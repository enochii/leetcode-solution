// 896. Monotonic Array
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int sz = unique(A.begin(), A.end()) - A.begin();
        if(sz < 3)return true;
        
        
        bool wsl = A[0] < A[1];
        
        for(int i=1;i<sz - 1;i++)
        {
            if((A[i] < A[i+1]) != wsl)return false;
        }
        return true;
    }
};