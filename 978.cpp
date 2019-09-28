// 978. Longest Turbulent Subarray

//Sliding Window
//分两种情况讨论，注意窗口延申到末尾的情况

class Solution {
public:
    // A[1] > A[2] < A[3] > A[4] < A[5])
    // For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
    // OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size()<2)return A.size();
        
        return max(single(A, true), single(A, false));
    }
    
    int single(vector<int>& A, bool mode){
        int ans = 0;
        
        // bool mode = false;
        int start = 0;
        // A.push_back(A.back());
        for(int i=0;i<A.size()-1;i++){
            if(mode){
                if(A[i] <= A[i+1]){
                    ans = max(ans, i+1 - start);
                    start = i+1;
                }
            }else{
                if(A[i] >= A[i+1]){
                    ans = max(ans, i+1 - start);
                    start = i+1;
                }
            }
            mode = !mode;
        }
        return max(ans,(int)A.size()-start);
    }
};