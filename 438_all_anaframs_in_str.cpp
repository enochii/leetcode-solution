#include <vector>

using namespace std;

//有点像之前的滑动窗口
//因为只有小写字母，所以用一个大小26的vector<int>来计数
//在遍历s利用上一次的结果构造计数数组，并与p的计数数组比较
class Solution{
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        const int n = p.size();
        if(s.size()<n){
            return res;
        }
        
        vector<int> cnt(26, 0);
        for(int i =0;i<n;i++){
            cnt[p[i]-'a']++;
        }

        vector<int> cnt_(26,0);
        for(int i=0;i<n;i++){
            cnt_[s[i]-'a']++;
        }
        if(cnt_==cnt){
            res.push_back(0);
        }
        for(int i=n;i<s.size();i++){
            cnt_[s[i-n]-'a']--;
            cnt_[s[i]-'a']++;
            if(cnt==cnt_){
                res.push_back(i-n+1);
            }
        }
        return res;
    }
};

//为什么会想到用求和来判断呢...
// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
//         vector<int> res;
//         if(s.size()<p.size()){
//             return res;
//         }
        
//         const int n = p.size();
        
//         int expected_sum  = 0;
//         for(int i=0;i<n;i++){
//             expected_sum+=p[i]-'a';
//         }
        
//         int sum = 0;
//         for(int i=0;i<n;i++){
//             sum+=s[i]-'a';
//         }
        
//         if(sum==expected_sum){
//             res.push_back(0);
//         }
        
//         for(int i=n;i<s.size();i++){
//             sum-=s[i-n]-'a';
//             sum+=s[i]-'a';
//             if(sum==expected_sum){
//                 res.push_back(i-n+1);
//             }
//         }
//         return res;
//     }
// };