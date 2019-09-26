// 392. Is Subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pos=0;
        int i=0;
        for(;i<s.size();i++){
            while(pos<t.size()&&t[pos]!=s[i])pos++;
            if(pos==t.size())return false;
            pos++;
        }
        
        return true;
    }
};