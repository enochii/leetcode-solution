// 576. Out of Boundary Paths

//Mem + DFS
//这里的节点是需要重复访问的，多次访问时N(剩余步数)不同
class Solution {
    const int MOD = 1000000007;
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    int findPaths(int m, int n, int N, int i, int j) {
        
        
        vector<vvi> steps(m, vvi(n, vi(N,-1)));
        
        return findPath(N,i,j,steps);
    }
    
    int findPath(int N, int i, int j, vector<vvi>& steps){
        if(i < 0 || i >= steps.size() || j < 0 || j >= steps[0].size()){
            return 1;
        }
        if(N == 0)return 0;
        
        auto & ans = steps[i][j][N-1];
        if(ans >= 0)return ans;
        return ans = ((findPath(N-1,i+1,j,steps)+findPath(N-1,i-1,j,steps))%MOD + 
                      (findPath(N-1,i,j+1,steps)+findPath(N-1,i,j-1,steps))%MOD) % MOD;
    }
};