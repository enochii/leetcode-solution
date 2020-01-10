// 697. Degree of an Array
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.empty())return 0;
        unordered_map<int, int> cnt;
        unordered_map<int, int> start;
        unordered_map<int, int> end;
        
        int maxCnt = 0;
        for(int i=0;i< nums.size();i++)
        {
            int num = nums[i];
            if(start.count(num)==0)
            {
                start[num]=i;
            }
            
            end[num] = i;
            ++cnt[num];
            
            maxCnt = max(maxCnt, cnt[num]);
        }
        
        int ans = INT_MAX;
        for(auto& p : cnt)
        {
            if(p.second == maxCnt)
            {
                // cout << start[p.first] << ' ' << end[p.first];
                ans = min(ans, end[p.first] - start[p.first]+1);
            }
        }
        return ans;
    }
};