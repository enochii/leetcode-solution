#include <vector>

using namespace std;

//要原地就弄多个状态呗，反正int可以表示的不止0 1
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //少于两个活着的邻居 ->  死亡
        //有2-3个活着的邻居 -> 就能活到下一代
        //多于三个活着的邻居 -> 死亡
        //刚好三个活着的邻居 -> 复活
        if(board.empty()||board[0].empty())return;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int cnt=count_neibor_live(i,j,board);
                if(board[i][j]){
                    if(cnt==2||cnt==3)continue;
                    board[i][j]=2;
                }else{
                    if(cnt==3)board[i][j]=3;
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]%=2;
            }
        }
    }
    
    int count_neibor_live(int r,int c,vector<vector<int>>& board){
        int cnt=0;
        for(int i=r-1;i<=r+1;i++){
            if(i>=board.size()||i<0){
                continue;
            }
            for(int j=c-1;j<=c+1;j++){
                if(j>=board[0].size()||j<0){
                    continue;
                }
                cnt+=board[i][j]==1||board[i][j]==2;
            }
        }
        return cnt-(board[r][c]==1||board[r][c]==2);
    }
};