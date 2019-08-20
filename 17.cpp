#include <vector>
#include <string>

using namespace std;

//别问，问就是暴力
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> kb={
            "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        vector<string> ans;
        string cur;
        _(cur,0,digits,kb,ans);
        return ans;
    }
    //
    void _(string& cur, int pos, const string& digits, vector<string> &kb,vector<string>& ans){
        if(pos==digits.size()){
            ans.push_back(cur);
            return;
        }
        int index=digits[pos]-'2';
        for(auto ch:kb[index]){
            cur.push_back(ch);
            _(cur,pos+1,digits,kb,ans);
            cur.pop_back();
        }
    }
};