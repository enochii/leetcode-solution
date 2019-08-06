#include <vector>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0] || (a[0]==b[0]&&a[1]<b[1]);
    }
};

//感觉还是区间问题...
//排序后遍历区间，看是否能够合并前后区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2)return intervals;
        sort(intervals.begin(), intervals.end(), cmp());

        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i+1][0]>intervals[i][1])continue;
            else{
                intervals[i]={};
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i+1][1],intervals[i][1]);
            }
        }
        for(auto inter:intervals){
            if(!inter.empty()){
                ans.push_back(inter);
            }
        }
        return ans;
    }
};