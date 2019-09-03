#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(int i=0;i<tokens.size();i++){
            if(isop(tokens[i])){
                int r=nums.top();nums.pop();
                int l=nums.top();nums.pop();
                int res=0;
                switch (tokens[i][0])
                {
                case '+':
                    res=l+r;
                    break;
                case '-':
                    res=l-r;
                    break;
                case '*':
                    res=l*r;
                    break;
                case '/':
                    res=l/r;
                    break;
                
                default:
                    break;
                }
                nums.push(res);
            }else{
                nums.push(strtoi(tokens[i]));
            }
        }
        return nums.top();
    }
    
    int strtoi(const string& s){
        int flag=1;
        int pos = 0;
        if(!isdigit(s[0])){
            if(s[0]=='-')flag=-1;
            pos++;
        }
        int res=0;
        while(pos<s.size()){
            res=res*10+s[pos]-'0';
            pos++;
        }
        return flag*res;
    }
    
    bool isop(const string& str){
        return (str[0]=='+'||str[0]=='-')&&str.size()==1 ||
            str[0]=='*'||str[0]=='/';
    }
};