// 646. Maximum Length of Pair Chain
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        if(n < 2)return n;
        
        auto cmp = [](const vector<int>& l, const vector<int>& r){
            return l[1] < r[1] ||
                    (l[1] == r[1] && l[0] > r[0]);
            };
        sort(pairs.begin(), pairs.end(), cmp);
        
        int prev = INT_MIN;
        int ans = 0;
        for(auto &p : pairs){
            if(p[0] > prev){
                ++ans;
                prev = p[1];
            }
        }
        
        return ans;
    }
};

class _Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int n = pairs.size();
        if(n < 2)return n;
        
        auto cmp = [](const vector<int>& l, const vector<int>& r){
            return l[1] < r[1] ||
                    (l[1] == r[1] && l[0] > r[0]);
            };
        sort(pairs.begin(), pairs.end(), cmp);
        
        vector<int> dp(n, 1);
        
        int ans = 0;
        //O(n*n)
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(pairs[i][0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};