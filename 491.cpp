// 491. Increasing Subsequences

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        recur(nums,0,cur,ans);

        return ans;
    }

    void recur(vector<int>& nums, int pos, vector<int>& cur,vector<vector<int>>& ans){
        if(cur.size()>=2){
            ans.push_back(cur);
        }
        //数字不是有序的，所以不能用那种相邻判断是否重复的方法
        unordered_set<int> mp;
        for(int i=pos;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())continue;
            if(!cur.empty()&&nums[i]<cur.back())continue;
            cur.push_back(nums[i]);
            recur(nums,i+1,cur,ans);
            cur.pop_back();
            mp.insert(nums[i]);
        }
    }
};


//https://leetcode.com/problems/increasing-subsequences/discuss/97134/Evolve-from-intuitive-solution-to-optimal
/*
 vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res(1);
        unordered_map<int,int> ht;
        for(int i=0;i<nums.size();i++) {
            int n = res.size();
            int start = ht[nums[i]];//从start开始可以避免重复
            ht[nums[i]] = n;
            for(int j=start;j<n;j++)
                if(res[j].empty() || res[j].back()<=nums[i]) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }  
        }
        for(int i=res.size()-1;i>=0;i--) 
            if(res[i].size()<2) {
                //看看别人是怎样erase的--
                swap(res[i],res.back());
                res.pop_back();
            }
        return res;
    }
*/