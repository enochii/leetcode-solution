// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

//binary search
class Solution {
public:
    int firstBadVersion(int n) {
        //我感觉就是二分吧
        int l=0,r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(isBadVersion(mid+1)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l+1;
    }
};