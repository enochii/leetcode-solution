#include <vector>

using namespace std;

//转转转
//画下示意图...
class Solution {
    vector<int> tmp;
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        // if(n<2){
        //     return;
        // }
        rotate(matrix, 0, n);
    }
    void rotate(vector<vector<int>>& mat, int start, int n){
        //
        if(n<2){
            return;
        }
        tmp = mat[start];
        for(int i=n-1;i>0;i--){
            mat[start][i+start]=mat[start+n-1-i][start];
            mat[start+n-1-i][start]=mat[start+n-1][n-1-i+start];
            mat[start+n-1][n-1-i+start]=mat[start+i][start+n-1];
            mat[start+i][start+n-1]=tmp[i+start];
        }
        // for(int i=n-1;i>0;i--){
        //     mat[start+n-1-i][start]=mat[start+n-1][n-1-i+start];
        // }
        // for(int i=n-1;i>0;i--){
        //     mat[start+n-1][n-1-i+start]=mat[start+i][start+n-1];
        // }
        // for(int i=n-1;i>0;i--){
        //     mat[start+i][start+n-1]=tmp[i+start];
        // }
        rotate(mat,start+1,n-2);
    }
};