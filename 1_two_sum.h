class Solution {
public:
    vector<int> twoSum_(vector<int>& nums, int target) {
        const int size = nums.size();
        
        // int i,j;
        for(int i = 0;i<size;i++){
            for(int j = i+1;j<size;j++){
                if(nums[i]+nums[j] == target){
                    return vector<int>{i,j};
                }
            }
        }
        return vector<int>();
    }
    vector<int> twoSum(vector<int>& nums, int target){
        const int size = nums.size();
        
        map<int, int> wow;
        for(int i=0;i<size;i++){
            if(wow.count(target - nums[i]))return vector<int>{wow[target-nums[i]], i};
            wow[nums[i]] = i;
        }
        return vector<int>();
    }
};