#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26]={0};
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(cnt[index]<=1)++cnt[index];
        }
        for(int i=0;i<s.size();i++){
            if(cnt[s[i]-'a']==1)return i;
        }
        return -1;
    }
};