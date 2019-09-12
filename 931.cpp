// 931. Minimum Falling Path Sum

#include <vector>
#include <algorithm>

using namespace std;

//DP

//为啥max不给个双迭代器的版本
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty()||A[0].empty())return 0;
        // if(A.size()==1)return 
        for(int i=A.size()-1;i>0;i--){
            for(int j=0;j<A[i-1].size();j++){
                int next=A[i][j];
                if(j>0){
                    next=min(next,A[i][j-1]);
                }
                if(j+1<A[i].size()){
                    next=min(next,A[i][j+1]);
                }
                A[i-1][j]+=next;
            }
        }
        int ret=INT_MAX;
        for(int i=0;i<A[0].size();i++){
            ret=min(ret,A[0][i]);
        }
        return ret;
    }
};