// 678. Valid Parenthesis String

class _Solution {
public:
    bool checkValidString(string s) {
        return check(s,0,0);
    }
    
    bool check(string& s, int pos,int lcnt){
        if(pos == s.size())return lcnt == 0;
        if(lcnt < 0)return false;
        if(s[pos] == ')'){
            // if(--lcnt < 0)return false;
            return check(s, pos+1, --lcnt);
        }
        if(s[pos] == '('){
            return check(s,pos+1,++lcnt);
        }
        
        return check(s, pos+1,lcnt+1) || 
            check(s, pos + 1,lcnt-1) || 
            check(s, pos+1,lcnt);
    }
};

//需要保证的是 忽略某些*的情况下左括号数量 = 右括号数量
//            不会先出现一个落单的右括号

//leftHigh记录大于左括号的最大可能数
//保证其>=0就不会有 Right parenthesis '(' go before the corresponding left parenthesis ')'.
//的情况
class Solution {
public:
    bool checkValidString(string s) {
        int leftHigh = 0, leftLow = 0;
        
        for(char c: s){
            if(c == '('){
                leftHigh ++;
                leftLow ++;
            }else if(c == ')'){
                leftHigh--;
                if(leftLow > 0)--leftLow;
            }else {
                leftHigh++;
                if(leftLow > 0)--leftLow;
            }
            if(leftHigh < 0)return false;
        }
        return leftLow == 0;
    }
};