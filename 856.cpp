// class Solution {
//     //(( ()() ) (()()))
// public:
//     int scoreOfParentheses(string s) {
//         //我们可以定义 集团：无法再拓展的一个单
//         int lcnt = 0;//还剩余的左括号数
//         int ans = 0;//总分数
//         int cur = 0;//当前 集团 的分数
//         int curlcnt = 0;
        
//         vector<int> curs;
        
//         for(char c : s){
//             // left = c =='(';
//             if(c == '('){
//                 lcnt ++;
//                 curlcnt ++;
//                 if(lcnt > 1){
//                     curs.push_back(cur);
//                     cur = 0;
//                     curlcnt = 0;
//                 }
//             }else{
//                 lcnt--;
//                 curlcnt--;
//                 if(cur == 0){
//                     cur = 1;
//                 }else{
//                     int all = cur;
//                     if(curlcnt > 0){
//                         for(int c:curs){
//                             all += c;
//                         }
//                         curs.clear();
//                     }
//                     cur = all * 2;
//                 }
//                 if(lcnt == 0){
//                     // cout<< cur <<' ' << 
//                     ans += cur;
//                     cur = 0;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// 856. Score of Parentheses
//有点牛逼
//不需要一次性把结果计算出来
//比如 ((())()) 当i=4就把((()) 给算了
class Solution {
    //(( ()() ) (()()))
public:
    int scoreOfParentheses(string s) {
        int lcnt = 0;
        int ans = 0;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                lcnt ++;
            }else{
                lcnt--;
                if(s[i-1] == '('){
                    ans += (1 << lcnt);
                }
            }
        }
        
        return ans;
    }
};