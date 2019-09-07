#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return false;
        int left=0,right=matrix.size();
        while(left<right){
            int mid=(left+right)/2;
            if(matrix[mid].front()>target){
                right=mid;
            }else if(matrix[mid].back()<target){
                left=mid+1;
            }else{
                return bsearch(matrix[mid],target);
            }
        }
        return false;
    }

    bool bsearch(vector<int>& vec,int target){
        if(vec.empty())return false;
        int l=0,r=vec.size();
        while(l<r){
            int mid=(l+r)/2;
            if(vec[mid]>=target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return target==vec[l];
    }
};