// 16. 3Sum Closest

//Two Pointer / 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++){
            if(target<=0&&nums[i]>0)break;
            int left=i+1,right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>target){
                    right--;
                }else if(sum<target){
                    left++;
                }else{
                    return target;
                }
                if(abs(closest-target)>abs(sum-target)){
                    closest=sum;                    
                }
            }
        }
        return closest;
    }
};