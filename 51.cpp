// 51. N-Queens

#include <vector>
#include <string>

using namespace std;

//八皇后 回溯额
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> cur(n,string(n,'.'));
        vector<vector<string> > ans;
        vector<int> cols(n,-1);//皇后被放在哪些列
        backtrack(ans,cur,0,cols);
        return ans;
    }

    void backtrack(vector<vector<string> > &ans, vector<string> &cur, int pos
        ,vector<int> cols
    ){
        const int n=cur.size();
        if(pos==n){//n queens has been placed
            return ans.push_back(cur);
        }
        //
        for(int i=0;i<n;i++){
            if(vaild(cols,pos,i)){
                cols[pos]=i;
                cur[pos][i]='Q';
                backtrack(ans,cur,pos+1,cols);
                // cols[pos]=i;
                cur[pos][i]='.';
            }
        }
    }

    bool vaild(vector<int>& cols, int pos, int col){
        for(int i=0;i<cols.size();i++){
            if(cols[i]==col||abs(cols[i]-col)==pos-i)return false;
        }
        return true;
    }
};