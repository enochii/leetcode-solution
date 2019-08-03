#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ret;
        
//         // unordered_map<int, int> st;
//         // for(int i=0;i<nums.size();i++){
//         //     st[nums[i]]++;
//         // }
//         const int len = nums.size();
//         for(int i=0;i<len-2;i++){
//             if(nums[i]+nums[i+1]+nums[i+2]>0)return ret;
//             if(nums[i]+nums[len-1]+nums[len-2])continue;
            
//             for(int j=i+1;j<len-1;j++){
//                 for(int k=j+1;k<len;k++){
//                     if(!nums[i]+nums[j]+nums[k]){
//                         ret.push_back({nums[i],nums[j],nums[k]});
//                     }
//                     while(k+1<nums.size()&&nums[k]==nums[k+1])k++;
//                 }
//                 while(j+1<nums.size()-1&&nums[j]==nums[j+1])j++;
//             }
//             while(i+1<nums.size()-2&&nums[i]==nums[i+1])i++;
//         }
//         return ret;
//     }

// };

//双指针
//疯狂避免重复
//指针修正还要考虑那种不重复的情况
//O(n^2)
//100 ms 14.5 MB
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        const int len = nums.size();
        for(int i=0;i<len-2;i++){
            int low = i+1;
            int high = len-1;
            while(low<high){
                int sum = nums[i]+nums[low]+nums[high];
                if(sum>0){
                    high--;
                }else if(sum<0){
                    low++;
                }else{
                    ret.push_back({nums[i],nums[low],nums[high]});
                    int old_low = nums[low];
                    while(low<high&&nums[low]==old_low)low++;
                    int old_high = nums[high];
                    while(low<high&&nums[high]==old_high)high--;
                }
            }
            int old_val = nums[i];
            while(i<len&&old_val==nums[i])i++;
            i--;
        }
        return ret;
    }
};