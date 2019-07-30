#include <vector>

using namespace std;

//跟快排的交换有点像
//换过来不是1要把i--
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = -1, high = nums.size();
        for(int i=0;i<high;i++){
            if(nums[i]==0){
                // cout<<"low: "<<low<<'\n';
                swap(nums[i], nums[++low]);
                if(nums[i]!=1&&i!=low){
                    i--;
                }
            }else if(nums[i]==2){
                swap(nums[i], nums[--high]);
                if(nums[i]!=1&&i!=high){
                    i--;
                }
                // cout<<"high: "<<high<<'\n';
            }
            //交换后再判断一手
            // if(nums[i]!=1){
            //     i--;
            // }
        }    
    }
};

class _Solution {
public:
    void sortColors(vector<int>& nums) {
        // int s0 = 0, s1 = 0, s2 =  0;
        int cnt[3] = {0};
        for(auto xi:nums){
            cnt[xi]++;
        }
        int i = 0;
        while(i<nums.size()){
            for(int j=0;j<3;j++){
                for(int k = 0;k<cnt[j];k++){
                    nums[i++] = j;
                }
            }
        }
    }
};