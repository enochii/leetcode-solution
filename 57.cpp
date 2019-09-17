#include <vector>

using namespace std;

//有一说1，erase有点慢

// ver1 -> 972ms
// ver2 -> 16ms
class _Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& interval) {
        //找到右端点比新区间左端点大(或者等于)的第一个区间
        //重叠从这里开始
        
        //在找到左端点比新区间右端点大的区间之前，疯狂合并
        
        //有一个比较巧的是也可以处理那种完全无重叠的case
        
        
        if(intervals.empty())return {interval};
        const int sz=intervals.size();
        int pos=0;
        for(;pos<sz;pos++){
            if(intervals[pos][1]>=interval[0])break;
        }
        //这里一个很吊的case是
        //就算完全不重叠的情况也是可以处理的
        auto it=pos+intervals.begin();
        for(;it!=intervals.end();){
            if((*it)[0]>interval[1])break;
            interval[0]=min((*it)[0],interval[0]);
            interval[1]=max((*it)[1],interval[1]);
            it=intervals.erase(it);
        }
        intervals.insert(it, interval);
        
        
        return intervals;
        
        //---------------//
        // int cur=0;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& interval) {
        if(intervals.empty())return {interval};
        const int sz=intervals.size();
        auto it = intervals.begin();
        
        vector<vector<int>> res;

        for(;it!=intervals.end();it++){
            if((*it)[1]>=interval[0])break;
            res.push_back(*it);
        }
        //这里一个很吊的case是
        //就算完全不重叠的情况也是可以处理的
        // auto it=pos+intervals.begin();
        
        for(;it!=intervals.end();it++){
            if((*it)[0]>interval[1])break;
            interval[0]=min((*it)[0],interval[0]);
            interval[1]=max((*it)[1],interval[1]);            
        }
        res.push_back(interval);
        for(;it!=intervals.end();it++){
            res.push_back(*it);
        }
        
        return res;
    }
};