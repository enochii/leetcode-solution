#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    //感觉用类似记忆化的手法
    //就是记录当前出去的最长increasing路径
    //然后类似dfs那样
    //时间复杂度好像只有O(n*n)？
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return 0;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(),-1));
        //
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans=max(ans,dfs(matrix,i,j,mem));
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int r,int c, vector<vector<int>>& mem){
        if(mem[r][c]!=-1)return mem[r][c];
        int maxi=0;
        static int dir[5]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+dir[i],nc=c+dir[i+1];
            if(nr<0||nr>=matrix.size()||nc<0||nc>=matrix[0].size())continue;
            if(matrix[nr][nc]>matrix[r][c]){
                maxi=max(maxi,dfs(matrix,nr,nc,mem));
            }
        }

        return mem[r][c]=maxi+1;
    }

};