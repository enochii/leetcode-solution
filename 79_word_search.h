static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Solution {
    int row_size, col_size;
    int offset[5] = {0, 1, 0, -1, 0};
    vector<vector<bool> > occupied;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row_size = board.size();
        if(row_size==0)return false;
        col_size = board[0].size();
        occupied = vector<vector<bool> >(row_size, vector<bool>(col_size, false));
        //
        const char* p = word.c_str();
        if(*p == '\0')return true;
        for(int r = 0;r<row_size;r++){
            for(int c = 0;c<col_size;c++){
                if(*p==board[r][c]&&move(board,p,r,c))return true;
            }
        }
        return false;
    }
    //当前在board[cur_row][cur_col]位置，字符串指针指向p位置
    bool move(vector<vector<char>>& board, const char* p,
             int cur_row, int cur_col){
        // if(*p == '\0')return true;
        if(*p != board[cur_row][cur_col])return false;
        if(*(p+1) == '\0')return true;
        occupied[cur_row][cur_col] = true;
        
        
        for(int i = 0;i<4;i++){
            int nr = cur_row + offset[i], nc = cur_col + offset[i+1];
            if(!valid(nr, nc))continue;
            // occupied[nr][nc] = true;
            if(move(board, p+1,nr, nc))return true;
            // occupied[nr][nc] = false;//roll back
        }
        occupied[cur_row][cur_col] = false;

        return false;
    }
    inline bool valid(int cur_row, int cur_col){
        return cur_row < row_size && cur_row >= 0 &&
                cur_col < col_size && cur_col >= 0 &&
                occupied[cur_row][cur_col] == false;
    }
};