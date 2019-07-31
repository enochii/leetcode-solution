#include <string>

using namespace std;

//一遍过？写得胆颤心惊--
//0 ms
//8.8 MB

//假设输入无问题
//很容易想到用递归下降来进行解析
//这东西还是用一个引用类型的pos指针来记录当前位置
//[]方括号内和整个字符串都是一样的形式
//(alpha|k[str])*
//看起来应该是括号内的不如整个字符串严格？

class Solution {
public:
    string decodeString(string s) {
        int pos=0;
        return helper(s, pos);
    }
    
    string helper(string& s, int &pos){
        if(s.size()<=pos){
            return "";
        }

        string res = "";
        while(s[pos]!=']'&&s[pos]!='\0'){
            while(isalpha(s[pos])){
                res+=s[pos];
                pos++;
            }
            if(isdigit(s[pos])){
                int lb_pos = s.find_first_of('[', pos);
                int k = stoi(s.substr(pos, lb_pos));
                pos = lb_pos+1;
                string substr = helper(s, pos);
                for(int i=0;i<k;i++){
                    res.append(substr);
                }
                pos+=1;//']'
            }
        }
        return res;
    }
};