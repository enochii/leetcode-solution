// 52. N-Queens II
class Solution {
    int ans;
public:
    int totalNQueens(int n) {
        vector<int> cols(n);
        ans = 0;
        
        recur(0,cols,n);
        return ans;
    }
    
    void recur(int row, vector<int> & cols, const int n){
        if(row == n){
            ans++;
            return;
        }
        for(int col = 0;col<n;col++){
            bool flag = true;
            for(int i=0;i<row;i++){
                if(cols[i] == col || abs(cols[i] - col) == row - i){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cols[row] = col;
                recur(row+1,cols,n);
            }
        }
    }
};