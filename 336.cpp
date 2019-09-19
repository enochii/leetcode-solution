#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    bool isPalin(const string& str){
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //abcd (abcd)左边
        //(dcba) dcba右边
        unordered_map<string, int> hash;
        for(int i=0;i<words.size();i++){
            hash.emplace(words[i],i);
        }
        //
        vector<vector<int>> ans;
        for(int i=0;i<words.size();i++){
            string& str=words[i];
            reverse(str.begin(),str.end());

            // bool l=false,r=false;
            //长度相同需要做判断防止压入两次
            //还有是空字符串...
            //长短那种包括一个为空的，都是长去搜短的，所以不会重复
            for(int j=0;j<=str.size();j++){
                auto left=str.substr(0,j);
                auto right =str.substr(j);
                auto it=hash.find(left);
                if(it!=hash.end()&&isPalin(right)&&i!=it->second){
                    ans.push_back({it->second,i});
                    // r=true;
                }
                it=hash.find(right);
                if(it!=hash.end()&&isPalin(left)&&i!=it->second&&j!=0){
                    ans.push_back({i,it->second});
                    // l=true;
                }
            }
        }
        return ans;
    }
    
    bool isPalin(const string& str){
        for(int i=0;i<str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1])return false;
        }
        return true;
    }
};
    }
};