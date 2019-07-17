class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> subset;
        search(0,nums.size(),subset,res,nums);
        return res;
    }
    void search(int cur, int max_dep, vector<int>& subset, vector<vector<int> >& res, vector<int>& nums){
        if(cur == max_dep){
            return res.push_back(subset);
        }
        subset.push_back(nums[cur]);
        search(cur+1, max_dep, subset,res,nums);
        subset.pop_back();
        search(cur+1,max_dep, subset,res,nums);
    }
};