// 740. Delete and Earn
// DP

//决策问题，一开始往这个方向走但不知道怎么搞状态转移
//如果我们把所有出现的数字都拿出来，走到一个数字看成一个阶段
//那么这就是一个类似一维背包的问题
//只要不同时拿到相邻的数字就行

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //把离散转成连续
        unordered_map<int, int> cnt;
        int maxn = 0;
        for(int num:nums){
            cnt[num]++;
            maxn = max(maxn, num);
        }
        //
        int yes = 0;
        int no = 0;
        
        // int lastyes;
        //连续做思路简单点，虽然一些数是并不存在的
        
        for(int i=1;i <= maxn;i++){
            int lastyes = yes;
            if(cnt.count(i)){
                yes = no + cnt[i] * i;
            }
            no = max(lastyes, no);
        }
        
        return max(yes, no);
    }
};