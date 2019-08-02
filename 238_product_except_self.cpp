#include <vector>

using namespace std;


class _Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> right(nums.size(),-1);
       vector<int> left = right;

        int lproduct = 1, rproduct = 1;
       for(int i=0;i<nums.size()-1;i++){
           left[i]=lproduct*nums[i];
           //
           int ri = nums.size()-1-i;
           right[ri]=rproduct*nums[ri];
       }
       vector<int> ret;
       for(int i=0;i<nums.size();i++){
           int l = i?left[i-1]:1;
           int r = i==nums.size()-1?1:right[i+1];
           ret.push_back(l*r);
       }
       return ret;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> ret(nums.size(),-1);

    //    int pro=1;
       ret[0]=1;
       for(int i=1;i<nums.size();i++){
        //    pro*=nums[i-1];
           ret[i]=nums[i-1]*ret[i-1];
       }

       int rpro = 1;
       for(int i=nums.size()-1;i>=0;i--){
           ret[i]*=rpro;
           rpro*=nums[i];
       }
       
       return ret;
    }
};