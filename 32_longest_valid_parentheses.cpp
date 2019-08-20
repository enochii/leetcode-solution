#include <string>
#include <vector>
#include <algorithm>


using namespace std;

// //第一反应是dp额
// //一个valid的str应该可以由两个相邻的str组成
// //或者由一个小的再加上首尾那种
//dp过不了...

// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
//         for(int i=0;i+2<s.size();i++){
//             if(s[i]='('||s[i+1]==')')dp[i][i+1]=true;
//         }
//         //
//         int limit=(s.size()>>1)<<1;
//         int ans=0;
        
//         for(int len=4;len<s.size();len+=2){
//             for(int i=0;i+len<s.size();i++){
//                 //
//                 if(s[i]=='('&&s[i+len-1]==')'&&dp[i+1][i+len-1-1]){
//                     dp[i][i+len-1]=true;ans=len;
//                     continue;
//                 }
//                 for(int j=2;j<len;j+=2){
//                     if(dp[i][i+j-1]&&dp[i+j][i+len-1]){
//                         dp[i][i+len-1]=true;ans=len;
//                         break;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

//另外，这种“以i结束”的trick挺常见的，说不出来的妙--

//另一种dp思路
//dp[i+1]表示以i结束的最长valid子串
//延续上一个复杂度爆炸的dp
//有两种情况需要讨论
//....()  ->  dp[i]=dp[i-2]+2
//....))  ->  ()(()) / (()) 所以除了加上2和dp[i-1]，还要注意非嵌套的部分，有点妙

class _Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<=1)return 0;
        vector<int> dp(s.size()+1,0);
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i+1]=dp[i-1]+2;
                }else{
                    //s[i-1]=s[i]=')'
                    if(dp[i]&&i-dp[i]-1>=0&&s[i-dp[i]-1]=='('){//i-1
                        dp[i+1]=2+dp[i]+dp[i-dp[i]-1];
                    }
                }
            }
            ans=max(ans,dp[i+1]);
        }
        return ans;
    }
};

//
#include <stack>

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> vec(s.size()+1,false);
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stk.push(i);
            else{
                if(!stk.empty()&&s[stk.top()]=='('){
                    vec[i]=vec[stk.top()]=true;
                    stk.pop();
                }
            }
        }
        //
        int ans=0;
        int cur=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]){
                // cout<<i<<' ';
                cur++;
            }else{
                ans=max(ans,cur);
                cur=0;
            }
        }
        return ans;
    }
};