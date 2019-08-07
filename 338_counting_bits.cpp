#include <vector>

using namespace std;

//相邻奇偶差1
// /2位数不变右移--
class Solution {
public:
    vector<int> countBits(int num) {    
        vector<int> ans(num+1,-1);
        ans[0]=0;
        for(int i=0;i<num;i++){
            ans[i+1]=(i+1)%2?ans[i]+1:ans[(i+1)/2];
        }
        return ans;
    }
};