#include <vector>
#include <string>

using namespace std;

//四个月前卡了很久的题
//当时看了思路就没动了
//这波一遍过...

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vs> mem(s.size());
        // mem[s.size()] = {""};
        vector<bool> vis(s.size(), false);

        dp(s,0,wordDict,mem,vis);
        
        return mem[0];
    }
    
    typedef vector<string> vs;
    bool dp(const string& s, int pos, const vs& dict,
            vector<vs>& mem,vector<bool>& vis
    ){
        if(pos == s.size()){
            return true;
        }
        //每个pos只会被访问一次
        if(vis[pos]){
            return !mem[pos].empty();
        }
        vis[pos] = true;//访问标志

        bool flag = false;
        for(auto& str:dict){
            if(s.substr(pos, str.size())==str){
                if(dp(s,pos+str.size(),dict, mem, vis)){
                    //只要匹配成功一次就是true
                    //不过需要把其他结果也遍历出来
                    //所以用一个flag变量记录
                    flag = true;
                    if(pos+str.size()==s.size()){
                        //不用补一个' '
                        mem[pos].push_back(str);
                    }else{
                        for(auto & after:mem[pos+str.size()]){
                            mem[pos].push_back(str+' '+after);
                        }
                    }
                }
            }
        }
        return flag;
    }
};