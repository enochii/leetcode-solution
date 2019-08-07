#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//因为温度范围是有限的，我们可以开一个next数组
//从后往前扫描，并更新nxt数组

//并且注意到我们不会用到遍历过的元素，可以用T数组作为返回数组来记录结果
class _Solution {
public:
    // typedef pair<int,int> ii;
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty())return T;
        
        vector<int> nxt(101,INT_MAX);
        
        for(int i=T.size()-1;i>=0;i--){
            int warmer_i = INT_MAX;
            for(int t=T[i]+1;t<=100;t++){
                warmer_i=min(warmer_i,nxt[t]);
            }
            nxt[T[i]]=i;
            T[i]=warmer_i==INT_MAX?0:warmer_i-i;
        }
        return T;
    }
};

//这个栈有点秀，虽然没法子用T做结果数组了
//从后往前遍历，stk存着历史数据的下标
//pop直到找到一个大于当前的数或者栈为空
//该数即是符合条件的最小下标

//一个骚点是我们pop数据无罪
//因为如果前面的数小于后面的数比如nums[j]<nums[i](j<i)，那么你是摸不到i后面的数的
//如果nums[i]>=nums[i+1]那么pop掉的数据本来也比你小!
//时间和空间复杂度应该都是O(n)
//但也就快乐几十ms的样子
class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty())return T;//size()-1如果是0会爆炸哦...
        stack<int> stk;//有点东西
        vector<int> ans(T.size(),0);
        for(int i=T.size()-1;i>=0;i--){
            int cur = T[i];
            while(!stk.empty()&&T[stk.top()]<=cur)stk.pop();
            if(!stk.empty()){
                ans[i]=stk.top()-i;
            }
            stk.push(i);
        }
        return ans;
    }
};