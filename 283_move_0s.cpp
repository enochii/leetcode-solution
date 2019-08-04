#include <vector>

using namespace std;

//记录两个指针not_0_pos和pos
//把非0的都往前移动，最后填入0即可
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int not_0_pos=0,pos=0;
        while(pos<nums.size()){
            if(nums[pos]!=0){
                if(not_0_pos!=pos){
                    nums[not_0_pos]=nums[pos];
                }
                not_0_pos++;
            }
            pos++;
        }
        for(int i=not_0_pos;i<nums.size();i++){
            nums[i]=0;
        }
    }
};