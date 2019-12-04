
//dfs时向下和右走就行
//走过做标记

//follow up要求没有修改且O(1)
//好像直接两层遍历
//是X就如果满足条件cond 就+1

// 419. Battleships in a Board
// cond -> 上面或者左边没有`X`，因为题目说不会有invalid的输入
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) 
    {
        int cnt = 0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] != 'X')continue;
                
                if((i == 0 || board[i-1][j] != 'X')
                  &&
                   (j == 0 || board[i][j-1] != 'X')
                  )++cnt;
            }
        }
        
        return cnt;
    }

};

