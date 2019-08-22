class Solution {
public:
//有趣的一个点是a+b == (a^b)+((a&b)<<1)
//而且注意到这样的递归中，b是在趋近0的
    int getSum(int a, int b) {
        return b?getSum(a^b,(a&b)<<1):a;
    }
};