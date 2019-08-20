#include <vector>
#include <string>
#include <set>

using namespace std;

//别问，问就是暴力
//n的字符串可以由n-1头尾接上一对括号
//或者由比它小的构成，这个需要循环遍历
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> ans={{"()"},};
        for(int i=2;i<=n;i++){
            help(i,ans);
        }

        // for(auto v:ans){
        //     for(auto s:v){
        //         cout<<s<<' ';
        //     }
        //     cout<<'\n';
        // }
        return ans[n-1];
    }
    //
    void help(int n, vector<vector<string>>& ans){
        set<string> cur;
        for(int i=1;i<n;i++){
            int j=n-i;
            //内层循环是同一个pre...，所以不要改它--
            for(auto &pre:ans[i-1]){
                for(auto &sub:ans[j-1]){
                    // if(n==3)cout<<i<<' '<<pre<<" "<<j<<' '<<sub<<"\n";
                    string pre_=pre;
                    pre_.append(sub);
                    cur.insert(pre_);
                }
            }
        }
        for(auto &mid:ans[n-2]){
            string str="(";
            str.append(mid);
            str.push_back(')');
            cur.insert(str);
        }
        ans.emplace_back(cur.begin(),cur.end());
    }
};