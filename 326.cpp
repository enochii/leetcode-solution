class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0)return false;
        return _(n);
    }
    bool _(int n){
        return n==1?true:(n%3==0&&_(n/3));
    }
};