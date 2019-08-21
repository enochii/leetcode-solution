#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//分治/递归
//先把小于k的char抹掉，并记录他们的位置
//这样就完成了当前递归层的分割
//然后在分隔开的子串寻找longestSubstring -> 新的子问题
class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> cnt(26, 0);
        for(auto ch:s){
            cnt[ch-'a']++;
        }
        vector<int> rm_chs;//char that need to removed
        //
        for(int i=0;i<s.size();i++){
            if(cnt[s[i]-'a']<k){
                rm_chs.push_back(i);
            }
        }
        if(rm_chs.empty())return s.size();
        rm_chs.push_back(s.size());//把最后一次结果切割出来
        //
        int longest=0;
        int cut_st=0;//start
        for(auto cut_pos:rm_chs){
            if(cut_pos-cut_st>=k){
                longest=max(longestSubstring(s.substr(cut_st,cut_pos-cut_st)
                ,k),longest);
            }
            cut_st=cut_pos+1;
        }
        return longest;
    }
};