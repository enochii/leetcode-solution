class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int cur=nums[0];
        int pos=1;
        for(int i=1;i<nums.size();i++){
            if(cur!=nums[i]){
                cur=nums[i];
                if(pos!=i)nums[pos]=nums[i];
                pos++;
            }else{
                
            }
        }
        int end=nums.size();
        while(pos<end){
            pos++;
            nums.pop_back();
        }
        return nums.size();
    }
};