#include <vector>

using namespace std;

//活久见
//递归dp跑了732ms，记忆化跑了32ms...

//写得好丑，我都不忍心看了...这个带记忆化的丑逼可以搞成dp的
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<char>> match(s.size()+1,vector<char>(p.size()+1,2));
        // match[s.size()][p.size()]=true;
        return xixi(0,0,s,p,match);
    }
    bool xixi(int si, int pi, const string& s, const string& p,vector<vector<char>>& match){
        if(match[si][pi]!=2)return match[si][pi];
        if(pi==p.size())return match[si][pi]=(si==s.size());
        if(si==s.size())return match[si][pi]=(p[pi]=='*'&&xixi(si,pi+1,s,p,match));
        if(p[pi]!='*')return match[si][pi]=((s[si]==p[pi]||p[pi]=='?') && xixi(si+1,pi+1,s,p,match));
        
        // (p[pi]=='*')
        return match[si][pi]=xixi(si+1,pi,s,p,match) || 
            xixi(si,pi+1,s,p,match);
    }
};

//
class _Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0]=true;
        // if(p[0]=='*'){
            for(int i=0;i<p.size();i++){
                if(p[i]=='*'){
                    dp[0][i+1]=dp[0][i];
                }else break;
            }
        // cout<<dp[0][1];
        // }
        //dp[i][j]
        for(int i=0;i<s.size();i++){
            for(int j=0;j<p.size();j++){
                //dp[i+1][j+1]
                if(s[i]==p[j]||p[j]=='?'){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                    // dp[i+1][j+1]=false;
                    if(p[j]=='*'){
                        for(int k=0;k<=i+1;k++){
                            if(!dp[k][j])continue;
                            dp[i+1][j+1]=true;break;
                        }
                    }
                }
            }
        }
        return dp.back().back();

    }
};