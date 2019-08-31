#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
//--
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        string res=strs[0];
        for(int i=1;i<strs.size();i++){
            if(res.empty())return "";
            const int min_sz=min(strs[i].size(),res.size());

            int pos;
            for(pos=0;pos<min_sz;pos++){
                if(strs[i][pos]!=res[pos])break;
            }
            res=res.substr(0, pos);
            // if(strs[i].size()<res.size()){
            //     // res=strs[i];
            //     int pos;
            //     for(pos=0;pos<strs[i].size();pos++){
            //         if(strs[i][pos]!=res[pos])break;
            //     }
            //     res=res.substr(0,pos);
            // }else{
            //     //
            //     int pos=res.size();
            //     for(int j=res.size();j>0;j--){
            //         if(strs[i][j-1]!=res[j-1]){
            //             pos=j-1;
            //         }
            //     }
            //     res=res.substr(0,pos);
            // }
        }
        return res;
    }
};