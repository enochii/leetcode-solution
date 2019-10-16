//枚举 Permutation
//判重的逻辑有点牛逼
//要在i被使用后才去查重


class Solution {
    int ans = 0;
public:
    int numTilePossibilities(string s) {
        sort(s.begin(), s.end());
        
        //enumurate
        vector<int> vis(s.size(), false);
        recur(vis,s);
        return ans;
    }
    
    void recur(vector<int>& vis, const string & s){
        
        for(int i=0;i<s.size();i++){
            if(vis[i]) continue;
            
            ans++;
            vis[i] = true;
            recur(vis, s);
            vis[i] = false;
            
            while(i+1<s.size() && s[i] == s[i+1])i++;
        }
    }
};