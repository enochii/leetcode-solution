#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> mp(26,26);
        for(int i=0;i<S.size();i++){
            mp[S[i]-'a']=i;
        }
        //
        auto cmp=[&mp](char l, char r){return mp[l-'a']<mp[r-'a'];};
        sort(T.begin(),T.end(),cmp);
        return T;
    }
};