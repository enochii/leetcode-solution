// #include <cmath>

class Solution {
public:
    int minSteps(int n) {
        if(n == 1)return 0;
        int divider = n - 1;
        for(;divider >= 1; divider--){
            if(n % divider == 0)break;
        }
        // std::cout<<divider<<'\n';
        return n/divider + minSteps(divider);
    }
};