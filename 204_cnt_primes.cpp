#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n<3)return 0;//注意素数计算的是小于3的
        //我记得有个啥素数筛法
        vector<bool> cands(n,true);
        int ans=1;//2 included
        //偶数也可以直接忽略
        for(int i=3;i<n;i+=2){
            if(cands[i]){
                ans++;
                int xx=i*3;
                while(xx<n){
                    cands[xx]=false;
                    xx+=i*2;
                }
            }
        }
        //
        
        // for(int i=2;i<n;i++){
        //     if(cands[i]){
        //         ans++;
        //     }
        // }
        return ans;
    }
};