// 40. Combination Sum II

#include <vector>
#include <algorithm>

using namespace std;

//tmd
//这种Combination有三种case
//可重复选择某数的排列(377)-> 0
//可重复选择某数的组合(39)-> i
//不可重复选择(原数组包含重复)的组合(40)-> i+1

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(),candidates.end());

        recur(candidates,target,ans,cur,0);
        return ans;
    }

    void recur(vector<int>& candidates, int todo, vector<vector<int>>& ans
        ,vector<int>& cur,int pos
    ){
        if(todo==0){
            ans.push_back(cur);
            return;
        }
        for(int i=pos;i<candidates.size();i++){
            if(candidates[i]>todo)continue;
            //i>pos!!! 避免重复
            if(i>pos&&candidates[i]==candidates[i-1])continue;
            //
            cur.push_back(candidates[i]);
            recur(candidates,todo-candidates[i],ans,cur,i+1);
            cur.pop_back();
        }
    }
};