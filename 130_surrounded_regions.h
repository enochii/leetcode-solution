class Solution {
//在标记为'O'的所有边界点进行dfs找到与其connected的所有cell，进行标记
//再对board再次进行全盘扫描，没有标记的'O'就flip成'X'

//we dfs from every bordered cell containing 'O', make a flag
//(for example, replace 'O' with '.')for all cells in the path.
//then, we scan the whole board, flip all the 'O's into 'X',
//also all the '.'s into 'O'(remove the flag that we made in dfs)

	//
    int row_size = 0, col_size = 0;
    
	void dfs(int row, int col, vector<vector<char>>& board){
		assert(board[row][col] == 'O');
		
		board[row][col]='.';//make a flag
		static int offsets[5] = {1,0,-1,0,1};
		for(int i = 0;i<4;i++){
			int new_col = offsets[i]+col;
			int new_row = offsets[i+1]+row;
			//
            if(new_col<0||new_col>col_size-1||new_row<0||new_row>row_size-1)continue;
			if(board[new_row][new_col] == 'O')
				dfs(new_row,new_col, board);
		}

	}
public:
    void solve(vector<vector<char>>& board) {
        row_size = board.size();
        if(row_size<=0)return;
        col_size = board[0].size();

        //first and last row
        for(int col = 0;col<col_size;col++)
        {
            if(board[0][col]=='O')dfs(0,col,board);
            if(board[row_size - 1][col]=='O')dfs(row_size-1,col,board);
        }
        // for(int col = 0;col<col_size;col++)
        // 	if(board[row_size - 1][col]=='O')dfs(row_size-1,col,board);
        //first and last col
        for(int row = 0;row<row_size;row++)
        {
        	if(board[row][0]=='O')dfs(row,0,board);
            if(board[row][col_size-1]=='O')dfs(row,col_size-1,board);
        }
        // for(int row = 0;row<row_size;row++)
        // 	if(board[row][col_size-1]=='O')dfs(row,col_size-1,board);

        //scan the board
        for(int row = 0;row < row_size;row++)
        	for(int col = 0;col < col_size;col++){
        		char& proxy = board[row][col];
        		if(proxy=='O')proxy='X';
        		else if(proxy=='.')proxy = 'O';//roll back
        	}
    }
};