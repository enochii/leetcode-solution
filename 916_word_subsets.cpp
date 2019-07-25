#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//我是真的蠢，为啥下面样例不能全过？？？
// Your input
// ["amazon","apple","facebook","google","leetcode"]
// ["e","o"]
// Output
// ["facebook","leetcode"]
// Expected
// ["facebook","google","leetcode"]
//虽然就算过了时间复杂度会爆炸。。。

// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
//         //不能预排序...
//         vector<string> res;
//         for(string& str:A){
//             vector<bool> used = vector<bool>(str.size(), false);
//             bool uni = true;
//             for(auto& str_:B){
//                 //检查A是否包含B
//                 if(!contains(str, str_, used)){
//                     uni = false;
//                     break;
//                 }
//             }
//             if(uni){
//                 res.push_back(str);
//             }
//         }

//         return res;
//     }

//     bool contains(string a, string b, vector<bool>& used){
//         int pos = 0;//字符串b的指针，朴素比较
//         for(int i=0;i<a.size();i++){
//             if(pos==b.size()){
//                 for(int j=0;j<pos;j++){
//                     //设置使用标志
//                     used[i-1-j]=true;
//                 }
//                 return true;
//             }

//             //i++已经做了
//             if(used[i]||a[i]!=b[pos]){
//                 i=i-pos;
//                 pos=0;
//             }else{
//                 pos++;
//             }
//         }
//         return false;
//     }
// };


class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        //不能预排序...
        vector<string> res;
        vector<int> b_cnt = alpha_cnt(B);
        
        for(const auto& xi:A){
            vector<int> a_cnt = alpha_cnt(xi);
            
            bool flag = true;
            for(int i=0;i<26;i++){
                if(a_cnt[i]<b_cnt[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.push_back(xi);
            }
        }

        return res;
    }
    
    // bool A_contains_B(vector<int> a_cnt, vector<int> b_cnt){
    //     for()
    // }

    vector<int> alpha_cnt(const vector<string> & B){
        vector<int> res=vector<int>(26, 0);
        for(auto& str:B){
            vector<int> cur = vector<int>(26, 0);
            for(char alpha: str){
                cur[alpha-'a']+=1;
            }
            for(int i=0;i<26;i++){
                res[i]=max(res[i],cur[i]);
            }
        }
        return std::move(res);
    }
    
    vector<int> alpha_cnt(const string& a){
        vector<int> res=vector<int>(26, 0);
        for(char alpha: a){
                res[alpha-'a']+=1;
        }
        return std::move(res);
    }
};