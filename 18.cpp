//判重的套路和以前类似哇
//降低算法复杂度用双指针喽
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        
        const int sz=nums.size();
        for(int i=0;i<sz-3;i++){
            //avoid duplicates
            if(i!=0)while(i<sz-3&&nums[i]==nums[i-1])i++;
            // if(sz==i+3)
            for(int j=i+1;j<sz-2;j++){
                if(j!=i+1)while(j<sz-2&&nums[j]==nums[j-1])j++;
                int l=j+1,r=sz-1;
                while(l<r){
                    // if(nums[i]==-2&&nums[j]==0){
                    //     cout<<nums[l]<<' '<<nums[r]<<'\n';
                    // }
                    int cur=nums[l]+nums[r]+nums[i]+nums[j];
                    if(cur==target){
                        ans.push_back({nums[l],nums[r],nums[i],nums[j]});
                        while(l<r&&nums[l]==nums[l+1])l++;
                        l++;
                        while(l<r&&nums[r]==nums[r-1])r--;
                        r--;
                    }else if(cur<target){
                        l++;
                    }else{
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};