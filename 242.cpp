#include <string>

using namespace std;

//嗷嗷，如果是unicode可以用map
class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26]={0};
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        for(auto ch:t){
            cnt[ch-'a']--;
        }

        for(auto c:cnt){
            if(c)return false;
        }
        return true;
    }
};