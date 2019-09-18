class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.empty())return ans;
        int start=nums[0];
        int cur=start;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==cur+1){
                cur++;
            }else{
                string starts=to_string(start);
                ans.push_back(cur==start?starts:starts+"->"+to_string(cur));
                start=cur=nums[i];
            }
        }
        
        string starts=to_string(start);
        ans.push_back(cur==start?starts:starts+"->"+to_string(cur));
        
        return ans;
    }
};