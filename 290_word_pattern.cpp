#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> sp_res = split(str);

        if(sp_res.size()!=pattern.size()){
            return false;
        }

        string maps[26] = {""};

        for(int i = 0;i<pattern.size();i++){

            int index = pattern[i]-'a';
            if(maps[index]==""){
                maps[index] = sp_res[i];
            }else if(maps[index]!=sp_res[i]){
                return false;
            }
        }
        
        //查重
        sort(maps, maps+26);
        for(int i=0;i<25;i++){
            if(maps[i]!=""&&maps[i] == maps[i+1])return false;
        }
        
        return true;
    }
    vector<string> split(string str){
        vector<string> res;

        int pos = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]==' '){
                if(i-pos>0){
                    res.push_back(str.substr(pos, i-pos));
                    // cout<<str.substr(pos, i-pos);
                    pos = i+1;
                }
            }
            // else{
            //     pos++;
            // }
        }
        res.push_back(str.substr(pos));

        return res;
    }
    
};