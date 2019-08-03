#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int> > ret;
        vector<int> one;
        generate(nums, 0, -1,one, ret);
        return ret;
    }

    void generate(vector<int>& nums, int cur, int last_index,vector<int>& one, vector<vector<int>> &ret){
        if(cur==nums.size()){
            ret.push_back(one);
            return;
        }
        generate(nums, cur+1,last_index,one,ret);
        //避免重复
        bool flag = false;
        if(!(cur!=0&&nums[cur]==nums[cur-1]&&last_index!=cur-1)){
            one.push_back(nums[cur]);flag = true;
            generate(nums,cur+1,cur,one,ret);
        }
        if(flag){
            one.pop_back();
        }
    }
};

class _Solution{
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int> > ret;
        vector<int> one;
        generate(nums, 0, one, ret);
        return ret;
    }
    void generate(vector<int>& nums, int pos, vector<int>& one, vector<vector<int>> &ret){
        ret.push_back(one);
        for(int i=pos;i<nums.size();i++){
            one.push_back(nums[i]);
            generate(nums,i+1,one,ret);
            one.pop_back();
            while(i+1<nums.size()&&nums[i]==nums[i+1]){
                i++;
            }
        }
    }
    
};