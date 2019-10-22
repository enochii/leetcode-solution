// 219. Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hs;
        
        for(int i=0;i<nums.size();i++){
            if(!hs.count(nums[i])){
                hs.emplace(nums[i],i);
            }else if(i - hs[nums[i]] <= k){
                return true;
            }else{
                hs[nums[i]] = i;
            }
        }
        
        return false;
    }
};