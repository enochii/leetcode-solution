#include <string>
#include <vector>

using namespace std;

//暴力递归
//firs_match还行
//*走两条路，match或者不match
class _Solution {
public:
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
    bool match(const string& s, const string& p, int sp, int pp){
        // if(sp==s.size()){
        //     return pp==p.size();
        // }
        if(pp==p.size()){
            return sp==s.size();
        }
        //
        bool first_match = sp<s.size()&& (s[sp]==p[pp] || p[pp] == '.');
        if(p.size()-pp >= 2&&p[pp+1]=='*'){
            return match(s,p,sp,pp+2) || //*不匹配
                (first_match&&match(s,p,sp+1,pp));//
        }else{
            return first_match && match(s,p,sp+1,pp+1);
        }
    }
};

//加个内存条--
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> mem(s.size()+1,vector<int>(p.size()+1, -1));
        return match(s,p,0,0,mem);
    }
    bool match(const string& s, const string& p, int sp, int pp, vector<vector<int>>& mem){
        if(pp==p.size()){
            return sp==s.size();
        }
        //
        if(mem[sp][pp]!=-1){
            return mem[sp][pp];
        }

        bool first_match = sp<s.size()&& (s[sp]==p[pp] || p[pp] == '.');
        if(p.size()-pp >= 2&&p[pp+1]=='*'){
            return mem[sp][pp]=match(s,p,sp,pp+2,mem) || //*不匹配
                (first_match&&match(s,p,sp+1,pp,mem));//
        }else{
            return mem[sp][pp]=first_match && match(s,p,sp+1,pp+1,mem);
        }
    }
};