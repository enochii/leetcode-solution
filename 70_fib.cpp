#include <map>
#include <vector>

using namespace std;

//这样看map还是很牛逼的，迭代和map差不多
//虽然我是傻逼，应该用vector
class _Solution {
    map<int, int> mem = {{1,1},{2,2}};
public:
    int climbStairs(int n) {
        if(mem.count(n))return mem[n];
        return mem[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};

class __Solution{
public:
    int climbStairs(int n){
        if(n==1||n==2)return n;
        
        int before1 = 1, before2 = 2;
        for(int i=3;i<=n;i++){
            int now = before1 + before2;
            before1 = before2;
            before2 = now;
        }
        return before2;
    }
};

//为啥大家都是4ms，佛了
class Solution{
    public:
    int climbStairs(int n){
        if(n<3)return n;
        vector<int> mem(n);
        mem[0]=1,mem[1]=2;
        for(int i=2;i<n;i++){
            mem[i]=mem[i-1]+mem[i-2];
        }
        return mem[n-1];
    }
};