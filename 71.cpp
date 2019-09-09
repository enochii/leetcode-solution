// 71. Simplify Path

#include <string>
#include <stack>

using namespace std;

//md lj
//像/..abc /...都可以我怎么玩
//这种题还是不要了吧 sb
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string cur="/";
        int pos=1;
        while(pos<path.size()){
            while(pos<path.size()&&'/'==path[pos])pos++;
            if(path[pos]=='.'){
                int dpos=pos;
                while(dpos<path.size()&&path[dpos]=='.')dpos++;
                int cnt=dpos-pos;
                if(cnt<=2&&(path[dpos]=='/'||dpos==path.size())){
                    pos=dpos;
                    if(cnt==2&&!stk.empty()){
                        cur=stk.top();
                        stk.pop();
                    }
                    continue;
                }
                // '/...' is valid...
            }
            //
            
            //
            int npos=pos;
            while(npos<path.size()&&path[npos++]!='/');
            // if(npos<path.size())npos++;//splash
            stk.push(cur);
            cur.append(path.substr(pos,npos-pos));
            pos=npos;
        }
        if(cur.back()=='/'&&cur.size()>1){
            cur.pop_back();
        }
        return cur;
    }
};