class Solution {
public:
    //只要让对方拿到4的倍数就赢了...
    bool canWinNim(int n) {
        return n%4!=0;
    }
};