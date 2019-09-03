//直接暴力
//这算啥Medium...
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cnt[9]={0};
        for(int i=0;i<9;i++){
            //每行
            memset(cnt,0,sizeof(cnt));//以字节为单位
            for(int c=0;c<9;c++){
                if(board[i][c]=='.')continue;
                if(++cnt[board[i][c]-'1']>=2)return false;
            }
            memset(cnt,0,sizeof(cnt));
            for(int r=0;r<9;r++){
                if(board[r][i]=='.')continue;
                if(++cnt[board[r][i]-'1']>=2)return false;
            }
        }
        //
        for(int sr=0;sr<9;sr+=3){
            for(int sc=0;sc<9;sc+=3){
                //
                memset(cnt,0,sizeof(cnt));
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        char ch=board[sr+i][sc+j];
                        if(ch=='.')continue;
                        if(++cnt[ch-'1']>=2)return false;
                    }
                }
                //
            }
        }
        return true;
    }
};