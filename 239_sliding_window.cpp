#include <vector>

using namespace std;

class _Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i=k-1;i<nums.size();i++){
            int start = i-k+1;
            int max_val = nums[start];
            for(int j=1;j<k;j++){
                if(max_val > nums[start+j]){
                    max_val = nums[start+j];
                }
            }
            res.push_back(max_val);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(k==0){
            return res;
        }
        int max_val = INT32_MIN, max_index;
        for(int i=0;i<k;i++){
            if(nums[i]>=max_val){
                max_val = nums[i];
                max_index = i;
            }
        }
        res.push_back(max_val);
        for(int i=k;i<nums.size();i++){
            if(max_val<=nums[i]){
                max_val = nums[i];
                max_index = i;
            }else if(max_index == i-k){
                max_val= INT_MIN;
                for(int j=i-k+1;j<i+1;j++){
                    if(max_val<=nums[j]){
                        max_val = nums[j];
                        max_index = j;
                    }
                }
            }
            res.push_back(max_val);
        }
        return res;
    }
};