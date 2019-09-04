#include <vector>

using namespace std;

//老实说，我觉得O(1)空间挺难的...
//
class _Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return {};
        //right/down/left/up limit
        //这四个变量围成的正方形(包括四条边)都是还没访问过的
        //向左访问一次要把上边界下移，其他类推(这个理解了就ok了 过过过)

        int rl=matrix[0].size()-1,dl=matrix.size()-1,ll=0,ul=0;
        // int r=0,c=0;
        vector<int> ans;
        while(true){
            //右
            for(int col=ll;col<=rl;col++)ans.push_back(matrix[ul][col]);
            if(++ul>dl)break;
            //下
            for(int row=ul;row<=dl;row++)ans.push_back(matrix[row][rl]);
            if(--rl<ll)break;
            //左
            for(int col=rl;col>=ll;col--)ans.push_back(matrix[dl][col]);
            if(--dl<ul)break;
            //上
            for(int row=dl;row>=ul;row--)ans.push_back(matrix[row][ll]);
            if(++ll>rl)break;
        }
        return ans;
    }
};

//
class Solution{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty())return {};
        //
        int rl=matrix[0].size()-1,dl=matrix.size()-1,ll=0,ul=0;
        int r=0,c=0;
        vector<int> ans;
        while(true){
            while(c<=rl){
                ans.push_back(matrix[r][c++]);
            }
            if(++ul>dl)break;
            c--;r++;
            //
            while(r<=dl){
                ans.push_back(matrix[r++][c]);
            }
            if(--rl<ll)break;
            r--;c--;
            //
            while(c>=ll){
                ans.push_back(matrix[r][c--]);
            }
            if(--dl<ul)break;
            c++;r--;
            //
            while(r>=ul){
                ans.push_back(matrix[r--][c]);
            }
            if(++ll>rl)break;
            r++;c++;
        }
        return ans;
    }
};