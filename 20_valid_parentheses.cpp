#include <stack>

using namespace std;

//0 ms
//8.6 MB
class Solution {
    stack<char> stk;
public:
    bool isValid(string s) {
        for(char c:s){
            if(c==')'||c==']'||c=='}'){
                if(stk.empty()||maps(stk.top())!=c)return false;
                stk.pop();
            }else{
                stk.push(c);
            }
        }
        return stk.empty();
    }
private:
    inline char maps(char c){
        if(c=='(')return ')';
        if(c=='[')return ']';
        if(c=='{')return '}';

        return '!';
    }
};