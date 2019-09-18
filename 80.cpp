class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)return nums.size();
        for(auto it=nums.begin();it!=nums.end();){
            int cur=*it;
            it++;
            if(it == nums.end()||*it != cur)continue;
            //
            it++;
            while(it!=nums.end()&&*it==cur){
                it=nums.erase(it);
            }
        }
        return nums.size();
    }
};