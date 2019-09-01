#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //感觉可以上dp
    //dp[i]表示从i开始到结尾可以有多少种解码方式
    //dp[i]=dp[i+1]+dp[i+2](需要看i和i+1的组合是否合法)
    //主要的坑在0喽，处理好一些边角条件就行
    int numDecodings(string s) {
        int pos=0;
        //日，题目感觉没说太清楚
        //如果不合法就直接gg返回0
        //一开始还以为把不合法的0给去掉...
        for(int i=0;i<s.size();i++){
            if(s[i]!='0'||(i>0&&(s[i-1]=='1'||s[i-1]=='2'))){
                // if(pos!=i)s[pos]=s[i];
                // pos++;
            }else{
                return 0;
            }
        }
        
        if(s.size()<2)return s.size();
        vector<int> dp(s.size(),0);
        char last=s[s.size()-1],last2=s[s.size()-2];
        if(last!='0')dp[s.size()-1]=1;
        if(bit2_valid(last2, last)){
            dp[s.size()-2]=1+dp[s.size()-1];
        }else if(last2=='0'){
            dp[s.size()-2]=0;
        }else{
            dp[s.size()-2]=1;
        }
        //
        if(s.size()==2)return dp[0];
        //
        for(int i=s.size()-3;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;continue;
            }
            dp[i]+=dp[i+1];
            if(bit2_valid(s[i],s[i+1])){
                dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
    bool bit2_valid(char last2, char last){
        return last2=='2'&&(last>='0'&&last<='6') || 
            last2=='1';
    }
};