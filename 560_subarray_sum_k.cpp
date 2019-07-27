#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

//这个故事告诉我们，状态转移方程太简单你用dp个锤子
//我好蠢...

// //MLE
// class _Solution {
//     // map<int, int> cnt;
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         //这道题用int就行了喂
//         int cnt = 0;
//         vector<vector<int> > mem(nums.size(), 
//             vector<int>(nums.size()));
        
//         // for(int i=0;i<nums.size();i++){
//         //     mem[i][i] = nums[i];
//         // }
//         //mem[r][c]表示从下表r+到c的和
//         for(int r=0;r<nums.size();r++){
//             for(int c=r;c<nums.size();c++){
//                 mem[r][c]=r==c?nums[r]:mem[r][c-1]+nums[c];
                
//                 int tmp = mem[r][c];
                
//                 if(tmp == k){
//                     cnt++;
//                 }
//                 // if(cnt.count(tmp)){
//                 //     cnt[tmp]++;
//                 // }else{
//                 //     cnt[tmp]=1;
//                 // }
//             }
//         }

//         return cnt;
//     }
// };

//

//暴力加法
class _Solution {
    // map<int, int> cnt;
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        
        for(int r=0;r<nums.size();r++){
            int sum = 0;
            for(int c=r;c<nums.size();c++){
                sum+=nums[c];
                if(sum==k)cnt++;
            }
        }

        return cnt;
    }
};

//还有另一种暴力是基于求出1~i(i=1,2,...,n)的和
//然后O(n^2)用减法枚举出所有结果
//这玩意事实上比上面的暴力还多了O(n)的存储
//不过基于这个idea可以用map加速一手

//这个用map的手段有点像在数组里面求两数之和为s的那道题
class Solution{
public:
    int subarraySum(vector<int>& nums, int k){
        unordered_map<int,int> cnt;
        int ret = 0;
        int sum = 0;
        cnt[0]=1;//让从下标1开始的有效
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(cnt.count(sum-k)){
                ret+=cnt[sum-k];
            }
            //这个是不是默认初始化为0啊
            cnt[sum]++;
        }
        return ret;
    }
};