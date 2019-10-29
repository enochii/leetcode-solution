// 367. Valid Perfect Square
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num == 1)return true;
        
        long long l = 1, r = num;
        while(l<r){
            long long mid = l+(r-l)/2;
            if(mid * mid < num){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l * l == num;
    }
};