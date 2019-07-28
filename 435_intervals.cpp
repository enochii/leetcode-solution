#include <algorithm>
#include <vector>

using std::vector;

//4 ms
//11.4 MB

//区间问题，活动安排的变形，直接贪心
//应该可以用总数减去活动安排的最大不重叠任务数

//下面的解法直接迭代，不符合就+1，并且把当前的y赋给下一个y
class Solution {
    struct cmp{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[1]<b[1];
        }
    };
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int sum = 0;
        
        sort(intervals.begin(), intervals.end(),cmp());
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1][1]>intervals[i][0]){
                sum++;
                intervals[i][1] = intervals[i-1][1];
            }
        }
        return sum;
    }
};