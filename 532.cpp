// 532. K-diff Pairs in an Array
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k<0)return 0;
        unordered_map<int,int> cnt;
        
        for(int num : nums){
            cnt[num]++;
        }
        
        int ans = 0;
        for(int num:nums){
            auto it = cnt.find(num - k);
            if(it == cnt.end())continue;
            
            if(k!=0){
                ++ans;
            }else if(it->second > 1){
                ++ans;
            }
            cnt.erase(it->first);
        }
        return ans;
    }
};