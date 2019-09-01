#include <string>
#include <vector>
#include <stack>

using namespace std;

// class Solution {
// public:
//     int calculate(string s) {
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='+'){
//                 return calculate(s.substr(0,i))+calculate(s.substr(i+1));
//             }else if(s[i]=='-'){
//                 return calculate(s.substr(0,i))-calculate(s.substr(i+1));
//             }
//         }
//         //no + or -
//         return cal_md(s);
//     }

//     int cal_md(string s){
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='*'){
//                 return cal_md(s.substr(0,i))*cal_md(s.substr(i+1));
//             }else if(s[i]=='/'){
//                 return cal_md(s.substr(0,i))/cal_md(s.substr(i+1));
//             }
//         }
//         return strtol(s.c_str(),(char**)0,10);
//     }
// };

enum{
    ADD=-4,
    SUB,
    MUL,
    DIV
};
//忘了叫啥算法
//这边先做预处理，把数字和符号解析到一个数组(越发感觉不用这一步，浪费了不少内存)
//然后用两个栈来搞优先级相关的计算
//

//还有一种做法是
//把加减法都先忽略，看成是正负号
//第一遍扫描只做乘除
//栈里剩下的数做下加法就行
class Solution {
public:
    int calculate(string s) {
        vector<int> transfer;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                char *pos;
                int num=strtol(s.c_str()+i,&pos,10);
                int npos=pos-s.c_str();
                i=npos-1;
                transfer.push_back(num);
            }else{
                switch (s[i])
                {
                case '+':
                    transfer.push_back(ADD);
                    break;
                case '-':
                    transfer.push_back(SUB);
                    break;
                case '*':
                    transfer.push_back(MUL);
                    break;
                case '/':
                    transfer.push_back(DIV);
                    break;
                default://space
                    break;
                }
            }
        }
        //
        // for(auto i:transfer){
        //     cout<<i<<" ";
        // }
        // cout<<'\n';
        stack<int> ops;
        stack<int> nums;
        for(int x:transfer){
            if(x>=0){
                nums.push(x);
            }else{
                //+ - * /
                int cur_lev=(-x-1)/2;
                while(!ops.empty()){
                    int top_lev=(-ops.top()-1)/2;
                    if(top_lev>cur_lev){
                        break;
                    }
                    int right=nums.top();nums.pop();
                    int left=nums.top();nums.pop();
                    int res=0;
                    switch (ops.top())
                    {
                        case ADD:
                            res=left+right;
                            break;
                        case SUB:
                            res=left-right;
                            break;
                        case MUL:
                            res=left*right;
                            break;
                        case DIV:
                            res=left/right;
                            break;
                        
                        default:
                            break;
                    }
                    ops.pop();
                    nums.push(res);    
                }
                ops.push(x);
            }
        }
        //
        while(!ops.empty()){
            int right=nums.top();nums.pop();
            int left=nums.top();nums.pop();
            int op=ops.top();ops.pop();
            int res;
            switch (op)
            {
                case ADD:
                    res=left+right;
                    break;
                case SUB:
                    res=left-right;
                    break;
                case MUL:
                    res=left*right;
                    break;
                case DIV:
                    res=left/right;
                    break;
                
                default:
                    break;
            }
            nums.push(res);
        }
        return nums.top();
    }
};