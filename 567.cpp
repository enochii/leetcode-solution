
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> cnt(26,0);
        for(int i=0;i<s1.size();i++){
            cnt[s1[i]-'a']++;
        }
        //
        const int sz1=s1.size(),sz2=s2.size();
        if(sz1>sz2)return false;
        //
        vector<int> cnt_(26);
        for(int i=0;i<sz1;i++){
            cnt_[s2[i]-'a']++;
        }
        if(cnt_==cnt)return true;
        //
        for(int i=sz1;i<sz2;i++){
            cnt_[s2[i-sz1]-'a']--;
            cnt_[s2[i]-'a']++;
            if(cnt==cnt_)return true;
        }

        return false;
    }
};