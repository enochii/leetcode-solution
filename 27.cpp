//就是stl的remove
//然而我也不知道为啥有这么多反对
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int pos = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                if(i!=pos){
                    nums[pos] = nums[i];
                }
                pos++;
            }
        }
        return pos;
    }
};