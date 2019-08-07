#include <vector>
#include <algorithm>

using namespace std;

//可以记录一个非负最大值和负数最大值，按需取即可
//类似最大和,不过要保留两个数,当前绝对值最大的正负乘积
//注意先后赋值...
//另外有一个trick是只要size大于等于2,最大积就必定大于0

typedef int ll;//原来不卡数据--

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        //以下推算结果至少为一个非负数

        ll pos_pro=nums[0]>0?nums[0]:0;
        ll neg_pro=nums[0]<0?nums[0]:0;
        //
        ll ans = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=0){
                pos_pro=pos_pro?pos_pro*nums[i]:nums[i];
                neg_pro=neg_pro?neg_pro*nums[i]:0;
                cout<<pos_pro<<' '<<neg_pro<<" pos \n";

            }else{
                // cout<<pos_pro<<' '<<neg_pro<<' '<<nums[i]<<" neg \n";
                int tmp=pos_pro;
                pos_pro=neg_pro?(neg_pro*nums[i]):0;
                neg_pro=tmp?(tmp*nums[i]):nums[i];
                // cout<<pos_pro<<' '<<neg_pro<<" neg \n";
            }
            ans=max(pos_pro,ans);
        }
        return ans;
    }
};