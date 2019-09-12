#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//用两个map一一对应就行了
//因为像ccc不能match "abb"这样的pattern
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i=0;i<words.size();i++){
            if(match(words[i],pattern)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }

    bool match(string& word, string& pat){
        unordered_map<char,char> mp;
        unordered_map<char,char> rmp;

        if(pat.size()!=word.size())return false;
        for(int i=0;i<pat.size();i++){
            if(mp.find(pat[i])!=mp.end()){
                if(mp[pat[i]]!=word[i])return false;
            }
            else{
                mp[pat[i]]=word[i];
            
            }
            if(rmp.find(word[i])!=rmp.end()){
                if(rmp[word[i]]!=pat[i])return false;
            }
            else{
                rmp[word[i]]=pat[i];
            }
        }
        return true;
    }
};