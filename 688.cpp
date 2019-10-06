// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

 //这道题有点迷惑
//总数是8^K次方
// 一开始以为停止的条件是步数走完或者出了棋盘
// ac题解是 从来没出过棋盘的走法 / (8^K)
class Solution {
    // int outcnt = 0;
    // int allcnt = 0;
    //typedef
    typedef vector<double> vi;
    typedef vector<vi> vvi;
    typedef vector<vvi> vvvi;
public:
    double knightProbability(int N, int K, int r, int c) {
        //事实上就是要求所有的move总数以及remain在棋盘内的总数
        //两者做浮点除法即可
        vvvi paths(N, vvi(N, vi(K, -1)));
        double rcnt = move(N, K, r, c, paths);
        return (double)rcnt/pow(8,K);
    }
    int dir[8][2] = {
        {-1, -2}, {-2, -1}, {-2, 1}, {-1,2}, {1, 2},{2,1},{2,-1},{1,-2}
    };
    double move(const int n, int k, int r, int c, vvvi& paths){
        if(r<0 || r>=n || c<0 || c>=n){
            return 0;//越界
        }
        if(k==0)return 1;
        
        auto & ans = paths[r][c][k-1];
        if(ans >= 0)return ans;
        ans = 0;
        for(int i=0;i<8;i++){
            int nx = r+dir[i][0];
            int ny = c+dir[i][1];
            
            ans += move(n,k-1,nx,ny,paths);
        }
        return ans;
    }
};

// class Solution {
//     // int outcnt = 0;
//     // int allcnt = 0;
//     //typedef
//     typedef vector<pair<long, long>> vi;
//     typedef vector<vi> vvi;
//     typedef vector<vvi> vvvi;
// public:
//     double knightProbability(int N, int K, int r, int c) {
//         //事实上就是要求所有的move总数以及remain在棋盘内的总数
//         //两者做浮点除法即可
//         vvvi paths(N, vvi(N, vi(K, {-1,-1})));
//         auto cnt = move(N, K, r, c, paths);
//         return (double)(cnt.second - cnt.first)/cnt.second;
//     }
//     int dir[8][2] = {
//         {-1, -2}, {-2, -1}, {-2, 1}, {-1,2}, {1, 2},{2,1},{2,-1},{1,-2}
//     };
//     pair<long,long> move(const int n, int k, int r, int c, vvvi& paths){
//         if(r<0 || r>=n || c<0 || c>=n){
//             return {1,1};//越界
//         }
//         if(k==0)return {0,1};
        
//         auto & ans = paths[r][c][k-1];
//         if(ans.first >= 0)return ans;
//         ans = {0,0};
//         for(int i=0;i<8;i++){
//             int nx = r+dir[i][0];
//             int ny = c+dir[i][1];
            
//             auto p= move(n,k-1,nx,ny,paths);
//             ans.first += p.first;
//             ans.second += p.second;
//         }
//         return ans;
//     }
// };