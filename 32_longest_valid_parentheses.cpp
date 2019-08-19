#include <string>
#include <vector>

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