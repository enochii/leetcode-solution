#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class _Solution {
public:
    int mySqrt(int x) {
        // if(x==0)return 0;
        for(int i=1;;i++){
            long long ii=(long long)i*i;
            if(ii>x)return i-1;
        }
    }
};

//这里可以二分...
//就是把int平方根的上下界求出来--
class Solution {
public:
    int mySqrt(int x) {
        int left=0, right=46341;//[)
        while(left<right){
            int mid=(left+right)/2;
            if(mid*mid>x){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left-1;
    }
};

// int main(){
//     //2147483647.0
//     cout<<((long long)46431*46431);
//     return 0;
// }