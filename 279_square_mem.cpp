#include <vector>
#include <algorithm>

using namespace std;

class _Solution {
public:
    //12就可以看出不能用贪心
    //那就上dp--
    int numSquares(int n) {
        int limit = (int)sqrt(n)+1;
        vector<int> nums(limit);
        vector<int> mem(n, INT_MAX);
        for(int i=0;i<limit;i++){
            nums[i]=(i+1)*(i+1);
        }
        //
        return recur(n, nums,mem);
    }
    int recur(int n, vector<int>& nums,vector<int>& mem){
        if(mem[n-1]!=INT_MAX){
            return mem[n-1];
        }
        
        //
        for(int i=0;i<nums.size();i++){
            if(n<nums[i])break;
            int left = n-nums[i];
            mem[n-1] = min(mem[n-1], left==0?1:1+recur(left,nums,mem));
        }
        return mem[n-1];
    }
};

class Solution{
    int numSquares(int n) {
        vector<int> mem(n+1, INT_MAX);
        mem[0]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;;j++){
                if(i<j*j)break;
                mem[i]=min(mem[i],1+mem[i-j*j]);
            }
        }
        return mem[n];
    }
};