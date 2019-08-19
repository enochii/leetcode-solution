#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans,candidates,0,target,cur);
        return ans;
    }

    void solve(vector<vector<int>>& ans,const vector<int>& cds,int pos,int remain,vector<int>& cur){
        if(remain==0){
            ans.push_back(cur);
            return;
        }
        //
        for(int i=pos;i<cds.size();i++){
            if(remain<cds[i])break;
            else{
                cur.push_back(cds[i]);
                solve(ans,cds,i,remain-cds[i],cur);
                cur.pop_back();
            }
        }
    }
};