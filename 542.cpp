// 542. 01 Matrix

#include <vector>
#include <algorithm>

#include <queue> //BFS

using namespace std;

//这种dfs有可能会重复遍历一个点，导致时间复杂度略高(1420 ms)
//并且其实有点bfs的痕迹
//
class _Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        //
        vector<vector<int>> mem(matrix.size(),vector<int>(matrix[0].size(),9999));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)dfs(matrix,i,j,mem,0);
            }
        }
        return mem;
    }

    void dfs(vector<vector<int>> & mat, int r,int c,vector<vector<int>>& mem, int dist){
        if(mat[r][c]==0){
            dist=0;
        }
        if(dist>=mem[r][c])return;
        mem[r][c]=dist;
        static int dir[5]={1,0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+dir[i];
            int nc=c+dir[i+1];
            if(nr<0||nc<0||nr>=mat.size()||nc>=mat[0].size())continue;
            dfs(mat,nr,nc,mem,dist+1);
        }
    }
};

//bfs 188ms
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    q.emplace(i,j);
                }else{
                    matrix[i][j]=INT_MAX;
                }
            }
        }
        //
        while (!q.empty())
        {
            auto& p=q.front();
            static int dir[5]={1,0,-1,0,1};
            for(int i=0;i<4;i++){
                int r=p.first+dir[i];
                int c=p.second+dir[i+1];
                if(r<0||c<0||r>=matrix.size()||c>=matrix[0].size())continue;
                //
                if(matrix[r][c]!=INT_MAX)continue;
                //
                matrix[r][c]=matrix[p.first][p.second]+1;
                q.emplace(r,c);
                // q.pop();
            }
            q.pop();
        }
        return matrix;
    }


};

//还有个dfs+dp的java跑了5ms???