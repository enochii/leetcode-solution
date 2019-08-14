#include <vector>
#include <string>
#include <map>

using namespace std;

//做映射
//两种不同的手法做
//排序字符串 or 计算26个小写字母的个数
//两者适应的i情况分别是字符串较小和较大...

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(int i=0;i<strs.size();i++){
            auto cnt=cnt_str(strs[i]);
            auto code=vec2str(cnt);
            mp[code].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto& kv:mp){
            ans.push_back(kv.second);
        }
        return ans;
    }

    vector<int> cnt_str(const string& str){
        vector<int> cnt(26,0);
        for(char ch: str){
            cnt[ch-'a']++;
        }
        return move(cnt);
    }
    string vec2str(const vector<int>& cnt){
        string ans;
        for(int i=0;i<26;i++){
            if(cnt[i]==0)continue;
            ans.push_back(i+'a');
            ans.push_back(cnt[i]);
        }
        return move(ans);
    }
};