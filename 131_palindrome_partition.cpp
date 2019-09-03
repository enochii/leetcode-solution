#include <vector>
#include <string>

using namespace std;

//下面的思路主要是先dp求出所有的回文串
//然后对于从某个下标开始的字符串
//我们可以枚举第一个合法的子回文串+后半部分的partition
//注意到这是个递归问题，我们可以利用记忆化去优化
//另外这里用了贼多的引用去避免不必要的复制
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())return {};

        //先求出合法的回文串
        vector<vector<bool> > dp(s.size(),vector<bool>(s.size(),false));
        for(int i=0;i<s.size()-1;i++){
            dp[i][i]=true;
            if(s[i]==s[i+1])dp[i][i+1]=true;
        }
        dp[s.size()-1][s.size()-1]=true;
        //
        for(int len=3;len<=s.size();len++){
            for(int i=0;i+len<=s.size();i++){
                if(dp[i+1][i+len-1-1]&&s[i]==s[i+len-1]){
                    dp[i][i+len-1]=true;
                }
            }
        }
        //进入第二波递归
        vector<vector<vector<string>>> mem(s.size(),vector<vector<string>>());
        mem.push_back({{}});//边界条件
        //
        return part(0,s,dp,mem);
    }

    //递归枚举
    //求出s从cur开始的所有partition
    vector<vector<string>>& part(int cur,const string& s,vector<vector<bool>>& dp
    ,vector<vector<vector<string>>>& mem
    ){
        if(!mem[cur].empty()){
            return mem[cur];
        }
        vector<vector<string>> &ans=mem[cur];
        // if(cur==s.size()){
        //     return {{}};
        // }
        for(int i=cur;i<s.size();i++){
            if(dp[cur][i]){
                auto& tmp=part(i+1,s,dp,mem);
                for(auto &vec:tmp){
                    // vec.insert(vec.begin(),s.substr(cur,i+1-cur));
                    ans.push_back(vec);
                    auto& ref=ans[ans.size()-1];
                    ref.insert(ref.begin(),s.substr(cur,i+1-cur));
                }
            }
        }
        return ans;
    }
};