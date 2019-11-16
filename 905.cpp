//有点像快排的思路
// 905. Sort Array By Parity

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = (int)A.size() - 1;
        
        while( l < r )
        {
            while(l<r && A[l] % 2 == 0)l++;
            while(l<r && A[r] % 2 == 1)r--;
            
            if(l<r)
            {
                swap(A[l], A[r]);
            }
        }
        
        return A;
    }
};