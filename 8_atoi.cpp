#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())return 0;
        int pos=0;
        //跳过前导空格
        while(pos<str.size()&&str[pos]==' ')pos++;
        
        int flag=1;
        //检查符号
        if(str[pos]=='-'){
            flag=-1;
            pos++;
        }else if(str[pos]=='+'){
            pos++;
        }
        //跳过sb前导0
        while(pos<str.size()&&str[pos]=='0')pos++;
        int start=pos;
        while(pos<str.size()&&isdigit(str[pos])){
            pos++;
        }
        //2147483647
        //截取数字部分
        str=str.substr(start,pos-start);//...请记好substr的第二个参数是长度，日
        // cout<<":"<<start<<" "<<pos<<":";
        if(str.empty())return 0;
        if(str.size()>10)return flag==1?INT_MAX:INT_MIN;
        //
        long long ret=0;//可能超过int...
        for(char ch:str){
            ret=ret*10+ch-'0';
        }
        if(flag==1&&ret>INT_MAX)return INT_MAX;
        if(flag==-1&&-ret<INT_MIN)return INT_MIN;
        return flag*ret;
    }
};