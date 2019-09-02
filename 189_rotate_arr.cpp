#include <vector>
#include <algorithm>

using namespace std;

//翻转大法好！
//把最后的几个数搞到前面
//分别再反转就行
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int sz=nums.size();
        k%=sz;
        //
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};