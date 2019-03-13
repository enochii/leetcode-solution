//this is the wrong version, note that what the 'connected' actually means,
//2 'connected' cells doesn't have to be adjacent! so we need dfs

/************************************************
	see the accepted one:"130_surrouned_regions.h"
************************************************/


// class Solution {
// public:
//     void solve(vector<vector<char>>& board) {
//         int row_size = board.size();
//         int col_size = board[0].size();
        
//         static int off[5] = {1,0,-1,0,1};

//         for(int row = 1;row < row_size - 1;row++){
//         	for(int col = 1;col <col_size - 1;col++){
//         		if('0' == board[row][col]){
//         			//4 surrounded cells
//         			for(int i = 0;i<4;i++){
//         				int new_row = row + off[i];
//         				int new_col = col + off[i+1];
//         				if(new_row<0||new_row>row_size-1)
//         					continue;
//         				if(new_col<0||new_col>col_size-1)
//         					continue;
//         				if((new_row==row_size-1||new_row==0||
//         					new_col == col_size-1||new_col==0)
//         					&&board[new_row][new_col] == '0')
//         					board[row][col] = 'X';
//         			}
//         		}
//         	}
//         }
//     }
// };