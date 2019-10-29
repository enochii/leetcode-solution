#include <string>
#include <unordered_map>

using namespace std;

//WA
//忘了作用域这回事。。。
//比如 "(let x 3 y (let x 2 x) x)"
//虽然忽略作用域我的结果(0)也错了.....

//又把substr的第二个参数当成end了。。。。
//传入的string参数没加双引号会爆炸 -> runtime error: pointer index expression with base 0x000000000000 overflowed to 0xffffffffffffffff (basic_string.h)
//过于硬核

class Solution {
    //用map存储let表达式
    unordered_map<string, int> env;
    
public:
    int evaluate(string& expression) {
        int pos = 0;
        // return -1;
        return evaluate(expression, pos);
    }
    
    int evaluate(string& exp, int &pos){
        // cout << pos <<'\n';
        whiteSpace(exp, pos);
        
        if(exp[pos] != '('){
            return leaf(exp, pos);
        }

        pos++; // -> (
        switch(exp[pos]){
            case 'l':
                pos+=3;
                whiteSpace(exp, pos);
                while(exp[pos]!='('){
                    int start = pos;
                    while(exp[pos]!= ' ' && exp[pos]!=')')++pos;
                    string var = exp.substr(start, pos-start);
                    whiteSpace(exp, pos);
                    
                    // cout << var <<" : ";
                    
                    if(exp[pos] == ')')return env[var];
                    
                    int val = evaluate(exp, pos);
                    env[var] = val;
                    // cout << val <<'\n';
                    whiteSpace(exp, pos);
                }
                if(exp[pos] == ')')++pos;
                return evaluate(exp, pos);
                
            case 'a':
                {
                    pos += 3;
                    whiteSpace(exp, pos);
                    int e1 = evaluate(exp, pos);
                    whiteSpace(exp,pos);
                    int e2 = evaluate(exp,pos);
                    if(exp[pos] == ')')++pos;
                    return e1 + e2;
                }
                
            case 'm':
                {
                    pos+=4;
                    whiteSpace(exp, pos);
                    int e1 = evaluate(exp, pos);
                    whiteSpace(exp,pos);
                    int e2 = evaluate(exp,pos);
                    
                    if(exp[pos] == ')')++pos;
                    return e1 * e2;
                }
            default :
                return -1;
        }
    }
    
    //var or number
    int leaf(string& exp, int& pos){
        // return -1;
        //number
        if(isdigit(exp[pos])){
            int ret = 0;
            do{
                ret = ret *10+(exp[pos] - '0');
            }while(isdigit(exp[++pos]));
            return ret;
        }
        
        //var
        int start = pos;
        while(exp[pos] != ')' && exp[pos]!= ' ')++pos;
        return env[exp.substr(start, pos - start)];
    }
    
    void whiteSpace(string& exp, int & pos){
        while(exp[pos] == ' ')++pos;
    }
};