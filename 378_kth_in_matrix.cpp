#include <vector>
#include <algorithm>

using namespace std;

//wdnmd，继续探索二分真谛

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int n=matrix.size();
        //
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r){
            int mid=(l+r)/2;
            int cnt=0;
            for(auto i=0;i<n;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            //记我们找的第k小的数为target
            //当l==r时，l是第一个不满足cnt<k的数，也就是我们要找的target！
            if(cnt<k){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        return l;
    }
};