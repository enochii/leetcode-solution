//从后往前会比从前往后快很多
//大概是剪枝比较快的原因
// 526. Beautiful Arrangement
class Solution {
    int ans;
public:
    int countArrangement(int N) {
        vector<bool> vis(N, false);
        ans = 0;
        recur(N, vis, N);
        return ans;
    }
    
    void recur(int pos, vector<bool>& vis, const int n){
        if(pos == 0){
            // cout<<'\n';
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i] || !valid(i+1, pos))continue;
            vis[i]= true;
            // cout<<i+1<<'('<<pos+1<<')'<<' ';
            recur(pos-1, vis,n);
            vis[i] = false;
        }
    }
    
    bool valid(int num, int ith){
        return (num % ith == 0) || (ith % num == 0);
    }
};