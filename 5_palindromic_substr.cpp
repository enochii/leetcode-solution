#include <string>
#include <vector>

using namespace std;

//日，还有一种从中心拓展出去的
//可以常量空间
//也就是遍历s的每一个下标，从i双向扩展
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2)return s;
        //
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()+1,false));
        for(int i=0;i<s.size();i++){
            dp[i][i+1]=true;//1
            dp[i][i]=true;
        }
        //0 1 已经初始化
        int mst=0,mlen=1;
        for(int len=2;len<=s.size();len++){
            for(int st=0;st+len<=s.size();st++){
                if(s[st]==s[st+len-1]&&dp[st+1][st+len-1]){
                    dp[st][st+len]=true;
                    if(mlen<len){
                        mlen=len;mst=st;
                    }
                }
            }
        }
        return s.substr(mst,mlen);
    }
};