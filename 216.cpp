// 216. Combination Sum III

#include <vector>

using namespace std;

//BackTracking

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cur;
        recur(0,k,n,ans,cur);
        
        return ans;
    }

    void recur(int pos,int remain_k, int todo
        ,vector<vector<int>>& ans,vector<int>& cur
    ){
        if(todo==0){
            if(remain_k>0)return;//没有0不可能了
            ans.push_back(cur);
            return;
        }
        if(remain_k<=0)return;//todo不为0,没有数了,不可能了
        //
        for(int i=pos;i<9;i++){
            if(i+1>todo)return;
            cur.push_back(i+1);
            recur(i+1,remain_k-1,todo-i-1,ans,cur);
            cur.pop_back();
        }
    }
};