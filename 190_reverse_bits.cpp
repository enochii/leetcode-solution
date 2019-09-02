class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res=0;
        // int cnt=32;
        for(int i=0;i<32;i++){
            res<<=1;//顺序很重要，保证最后一个bit刚好在第一位
            res=res|(n&1);
            n>>=1;
        }
        return res;
    }
};