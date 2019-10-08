// 77. Combinations
//Backtracking
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        recur(n, 1, k, cur, ans);
        
        return ans;
    }
    
    void recur(const int n, int pos, int k, vector<int>& cur, vector<vector<int>> & ans){
        // cout<<'?';
        if(k == 0){
            ans.push_back(cur);
            return;
        }
        if(n < pos){
            return;
        }
        //
        for(int i=pos;i<=n;i++){
            cur.push_back(i);
            recur(n,i+1,k-1,cur,ans);
            cur.pop_back();
        }
    }
};