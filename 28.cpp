#include <string>

using namespace std;

//感觉可以用那个kmp的
//不过好像没必要了..暴力就行
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())return 0;
        if(haystack.size()<needle.size())return -1;
        //
        for(int i=0;i<=haystack.size()-needle.size();i++){
            int pos=0;
            while(pos<needle.size()){
                if(haystack[pos+i]==needle[pos]){
                    pos++;
                }else{
                    break;
                }
            }
            if(pos==needle.size())return i;
        }
        return -1;
    }
};