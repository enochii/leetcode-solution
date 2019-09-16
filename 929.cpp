#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        
        for(auto& str:emails){
            st.insert(filter(str));
        }
        return st.size();
    }

    string filter(string& s){
        string ret=s;
        int i;
        int pos=0;//有效位置
        for(i=0;i<s.size();i++){
            if(s[i]=='@'||s[i]=='+'){
                break;
            }
            if(s[i]=='.')continue;
            if(i!=pos){
                s[pos]=s[i];
            }
            pos++;
        }
        //
        while(s[i]!='@')i++;
        return i==pos?s:s.substr(0,pos)+s.substr(i);
    }
};