// 509. Fibonacci Number
class Solution {
public:
    int fib(int n) {
        if(n<2)return n;
        
        int a = 1, b = 1;
        for(int i=2;i<n;i++){
            int tmp = a+b;
            a=b;
            b = tmp;
        }
        return b;
    }
};