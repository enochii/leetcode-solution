//2的因子比5多
//比如25!
//25/5 = 5 -> 25 20 15 10 5
// 5/5 = 1 -> 25的第二个5
class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        while(n){
            n/=5;
            res+=n;
        }
        return res;
    }
};