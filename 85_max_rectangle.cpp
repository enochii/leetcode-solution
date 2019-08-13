#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//.....................
//tmd 又是单调栈
//遍历每一行
//将高度从上往下叠，遇到0就从零开始
//对于每一行，我们认为它是直方图的顶峰，高度从上往下延申，这样就变成了n个(LeetCode 84)直方图的问题

//这道题我还以为是那道dp最大边长正方形的变体
//然而根本找不出状态转移方程，状态明显会多不少?
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m=matrix.size();
        const int n=m?matrix[0].size():0;

        if(m==0||n==0)return 0;
        vector<int> heights(n+1,0);//最后一个是辅助0哦

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                heights[j]=matrix[i][j]=='0'?0:1+heights[j];
            }
            int tmp=histogram(heights);
            ans=max(tmp, ans);
        }
        return ans;
    }

    int histogram(const vector<int> & heights){
        stack<int> stk;
        int ans=0;
        for(int i=0;i<heights.size();i++){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                int prev=stk.top();
                stk.pop();
                //两边都是不低于heights[i]
                int tmp=(stk.empty()?i:(i-stk.top()-1))*heights[prev];
                ans=max(tmp,ans);
            }
            stk.push(i);
        }
        return ans;
    }
};