// 875. Koko Eating Bananas

//Binary Search

//最慢且满足要求的速度

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int r=0;
        long long sum=0;
        for(int pile:piles){
            r=max(r,pile);
            sum+=pile;
        }
        int l = (sum-1)/H+1;
        //
        // int l = 1;
        //虽然区间右端是开的，但是可以被取到嗷
        while(l < r){
            int mid=(l+r)/2;
            int cnt=count(piles,mid);
            if(cnt > H){
                l = mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
    
    int count(vector<int>& piles, int k){
        int cnt=0;
        for(int pile:piles){
            cnt+=(pile-1)/k + 1;
        }
        return cnt;
    }
};