#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

//感觉之前做过一道简单的递归栈，不过现在还是没能理解精髓...
//该题目要求求面积最大的矩形
//维护一个直方高度单调非递减(也可以做成递增)的栈
//栈内存放的是索引
//对于栈顶两个相邻的索引i和j(i<j)，(i,j]内的矩形高度均会大于等于heights[j]
//设cur为heights的当前索引，那么[j,cur)的高度也会大于等于heights[j]
//那么高度为heights[j]的包括j的最大矩形的长就是(cur-i-1)

//递增比非递减的优势是不用计算一些高度相同而长度不同的矩形，也就是计算一些不需计算的结果
//然而时间基本上差不多
//以下代码只需改动：1.在高度数组开始插入-1 2.while判断变为>=
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //这个算是一个优化...可以避免判断栈是否为空
        heights.insert(heights.begin(),0);
        heights.push_back(0);//这个比较必要吧,把所有的矩形都逼出来
        stack<int> stk;
        stk.push(0);
        int ans = 0;
        //维护一个单调递增栈
        for(int i=1;i<heights.size();i++){
            while(/*!stk.empty()&& */
                    heights[stk.top()]>heights[i]){
                int top = stk.top();
                stk.pop();
                int tmp=(/*stk.empty()?i: */i-stk.top()-1)*heights[top];
                ans=max(tmp,ans);
            }
            // }
            stk.push(i);
        }
        return ans;
    }
};