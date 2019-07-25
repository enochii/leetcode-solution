#include <vector>
#include <string>

using namespace std;

// Runtime: 0 ms/sometimes 4ms...
// Memory Usage: 8.7 MB

class Solution {
    //0->false
    //1->true
    //2->uncaculated
    //mem[pos]表示从pos开始能否被word break
    vector<int> mem;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        mem.assign(s.size(), 2);

        return valid(s, wordDict, 0);
    }
    
    
    bool valid(const string& s, vector<string>& wordDict, int pos){
        if(pos == s.size())return true;
        if(mem[pos]!=2)return mem[pos];

        for(const auto& str:wordDict){
            if(startwith(str, s, pos)
            && valid(s, wordDict, pos+str.size())){
                return mem[pos] = 1;
            }
        }
    }

    bool startwith(const string& str, const string& s, int pos){
        if(s.size()-pos<str.size())return false;
        for(int i=0;i<str.size();i++){
            if(str[i]!=s[pos+i])return false;
        }

        return true;
    }
};