#include <stdlib.h>

class Solution {
    //还有一个坑是倒过来超过INT_MAX...
    //所以上long long吧
public:
    int reverse(int x) {
        if(x==INT_MIN)return 0;
        //
        int flag=x>0?1:-1;
        x*=flag;
        long long res=x%10;
        x/=10;
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        res*=flag;
        if(res>INT_MAX||res<INT_MIN)return 0;
        return res;
    }
};