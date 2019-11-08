// 1222. Queens That Can Attack the King

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        //事实上最多只有8个queen可以够得到king
        vector <vector<char>> gra(8,vector<char> (8, 0));
        for(auto& q:queens)
        {
            gra[q[0]][q[1]] = 1;
        }
        
        vector<vector<int>> ans;
        int dir[8][2] = {
            {1,0}, {0,1}, {-1, 0}, {0, -1},
            {1,1}, {-1,-1}, {-1,1}, {1,-1},
        };
        
        for(int i = 0;i<8;i++)
        {
            int ret = move(dir[i][0], dir[i][1], gra, king);
            if(ret != -1)
            {
                ans.push_back({king[0]+dir[i][0]*ret, king[1]+dir[i][1]*ret});
            }
        }
        return ans;
    }
    
    int move(int dr, int dc, vector <vector<char>> &g, vector<int>& king)
    {
        int kr = king[0], kc = king[1];
        for(int i=0;i<8;i++)
        {
            kr+=dr, kc +=dc;
            if(kr < 0 || kc < 0 || kr >= 8 || kc >= 8)return -1;
            
            if(g[kr][kc])
            {
                return i+1;
            }
        }
        
        return -1;
    }
};