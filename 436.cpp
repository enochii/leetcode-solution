// 436. Find Right Interval

#include <vector>
#include <algorithm>

using namespace std;

//Binary Search
//找到每个区间i的延续区间j
//要求j的起点大于等于i的终点，并且最小化j
//看到tag才会写额
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        //我感觉可以来一个下标数组
        auto cmp=[&intervals](int l, int r){
            return intervals[l][0]<intervals[r][0];
        };
        //
        vector<int> index(intervals.size());
        for(int i=0;i<index.size();i++){
            index[i]=i;
        }
        //我感觉要稳定排序哦
        //不稳定也能过...感觉不太科学，可能是testcase不够多
        stable_sort(index.begin(),index.end(),cmp);
        //
        // for(int i=0;i<index.size();i++){
        //     cout<<index[i]<<' ';
        // }
        
        vector<int> ans(index.size());
        //
        for(int i=0;i<ans.size();i++){
            ans[i]=bsearch(i,intervals,index);
            // cout<<ans[i];
        }
        return ans;
    }

    int bsearch(int i, vector<vector<int>>& intervals, vector<int>& index){
        int l=0, r=intervals.size();
        while(l<r){
            int mid=l+(r-l)/2;
            if(intervals[index[mid]][0]>=intervals[i][1]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        
        return l==index.size()?-1:index[l];
    }
};