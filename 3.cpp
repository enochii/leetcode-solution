#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

//wdnmd! Sliding Windows
//用一个map存char和它对应的下标
//map里面的都是无重复的char
//如果新扫到的char重复就要跳跃
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int /*mleft=0,*/mlen=0,cleft=0;//current left
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()
               &&cleft<=mp[s[i]]){//注意这里的判断，也就是在map里面的s[i]是否是有效的...有点东西
                //
                if(mlen<i-cleft){
                    mlen=i-cleft;
                    // mleft=cleft;
                }
                int new_cleft=mp[s[i]]+1;
                //懒删除就行了...
                //判断是否大于cleft就行orz
                // for(int j=cleft;j<new_cleft;j++){
                //     mp.erase(s[j]);
                // }
                cleft=new_cleft;//update mleft
            }
            mp[s[i]]=i;//update
        }
        mlen=max(mlen,(int)s.size()-cleft);//需要把最后一波搞出来
        return mlen;
    }
};