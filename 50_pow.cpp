class Solution {
public:
    //注意取正数有个testcase n=INT_MIN
    double myPow(double x, int n) {
        if(n<0){
            if(n==INT_MIN){
                int sq=myPow(x,n/2);
                return sq*sq;
            }else{
                return myPow(1/x,-n);
            }
        }
        if(n==0)return 1;
        if(n%2==1)return x*myPow(x,n-1);
        //n%2==0
        double sq=myPow(x,n/2);
        return sq*sq;
    }
};