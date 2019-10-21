// 539. Minimum Time Difference
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        
        for(string& tp:timePoints){
            int pos = 0;
            int h = convert(tp, pos);
            pos+=3;
            int m = convert(tp, pos);
            // if(h+m==0)h=24;
            
            times.emplace_back(h*60 + m);
        }
        
        sort(times.begin(), times.end());
        times.emplace_back(1440 + times.front()); 
        //默认时间可以是隔一天的，所以让最小时间加上24小时，形成一个环
        
        int ans = INT_MAX;
        for(int i=0;i+1<times.size();i++){
            int diff = times[i+1] - times[i];
            
            ans = min(ans, diff);
        }
        return ans;
    }
    
    int convert(string& s, int pos){
        return (s[pos]-'0')*10 + s[pos+1]-'0';
    }
};