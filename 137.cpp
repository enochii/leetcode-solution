// 137. Single Number II
//谁又能想到是位操作呢
//没有只出现一次的那个数，每一个位都会是3的倍数
//过于trick
class _Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32, 0);
        
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<32;j++){
                cnt[j] += ((nums[i] >> j)&1);
                cnt[j] %= 3;
            }
        }
        
        int ans = 0;
        for(int i=0;i<32;i++){
            ans |= (cnt[i]<<i);
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int cnt;
        for(int j=0;j<32;j++){
            cnt = 0;
            for(int i=0;i<nums.size();i++){
                cnt += ((nums[i] >> j)&1);
                
            }
            cnt %= 3;
            ans |= (cnt << j);
        }
        
        return ans;
    }
};