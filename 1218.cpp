// 1218. Longest Arithmetic Subsequence of Given Difference

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        const int n = arr.size();
        // vector<int> dp(n, 1);
        
        unordered_map<int, int> mp;
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int curLen = 1;
            auto it = mp.find(arr[i] - diff);
            if(it != mp.end())
            {
                // cout << it->first <<' ' <<it->second <<'\n';
                curLen = it->second + 1;
            }
            
            it = mp.find(arr[i]);
            if(it != mp.end())
            {
                mp[arr[i]] = max(it->second, curLen);
            }
            else{
                mp[arr[i]] = curLen;
            }
            
            ans = max(mp[arr[i]], ans);
            // cout << mp[arr[i]] <<' ';
        }
        return ans;
    }
};