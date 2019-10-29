// 784. Letter Case Permutation
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        
        recur(S,0,ans);
        return ans;
    }
    
    void recur(string &s, int pos, vector<string>& ans){
        
        if(s.size() <= pos){
            // cout << pos<<' ';
            ans.push_back(s);
            return;
        }
        
        for(;pos<s.size();pos++){
            if(isalpha(s[pos]))break;
        }
        
        recur(s,pos+1,ans);
        
        if(pos == s.size())return;
        
        if(islower(s[pos])){
            s[pos] += 'A'-'a';
        }else{
            s[pos] += 'a'-'A';
        }
        //没有字幕就不需要走第二遭了
        return recur(s,pos+1,ans);
    }
};