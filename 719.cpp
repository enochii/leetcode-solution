#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//Binary Search
// 719. Find K-th Smallest Pair Distance
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        const int n = nums.size();
        int l = 0, r = nums.back() - nums[0];
        while(l < r){
            //内层循环O(n)
            //这个start过于牛逼
            //对于i<j
            //nums[i] - nums[start]如果差值大于mid
            //那么nums[j] - nums[start]必然大于mid
            int mid = (l+r)/2;
            int cnt = 0, start = 0;
            for(int i=0;i<n;i++){
                //作为较大的数时，在[start, i)范围内 差值小于mid
                while(start < i && nums[i] - nums[start] > mid)start++;
                cnt += i - start;
            }

            if(cnt < k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};

//O(n*n)
//TLE
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         vector<int> diff;
//         for(int i =0;i< nums.size();i++){
//             for (int j=i+1;j<nums.size();j++){
//                 diff.push_back(abs(nums[j] - nums[i]));
//             }
//         }
        
//         // sort(diff.begin(), diff.end());
        
//         //partition
//         return searchK(k, diff.begin(),diff.end());
//     }
//     typedef vector<int>::iterator It;
//     It partition (It first, It last){
//         int tmp = *first;
//         --last;
//         while(first < last){
//             while (first < last && *last >= tmp)--last;
//             *first = *last;
//             while (first < last && *first <= tmp)++first;
//             *last = *first;
//         }
//         *first = tmp;
//         return first;
//     }

//     int searchK(int k, It first, It last){
//         auto it = partition(first, last);

//         int pos = it - first+1;
//         if (pos == k){
//             return *it;
//         }else if(pos > k){
//             return searchK(k-pos,it,last);
//         }else{
//             return searchK(k, first, it);
//         }
//     }
// };
