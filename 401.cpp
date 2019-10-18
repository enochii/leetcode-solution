// 401. Binary Watch
//hint : A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> times = {1,2,4,8,16,32,60,120,240,480};
        vector<string> ans;
        
        recur(times,0,0,0,num,ans);
        return ans;
    }
    
    void recur(vector<int>& times, int pos, int h, int m, int remain, vector<string>& ans){
        if(remain == 0){
            if(h>11 || m > 59)return;
            
            string s = to_string(h)+':';
            if(m < 10)s+='0';
            s+=to_string(m);
            
            ans.push_back(s);
            return;
        }
        if(pos == times.size())return;
        
        for(int i =pos;i<times.size();i++){
            recur(times, i+1, h+times[i]/60,m + times[i]%60, remain - 1, ans);
        }
    }
};