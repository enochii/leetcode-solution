#include <vector>

using namespace std;

class _Solution {

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m=matrix.size(),n = m==0?0:matrix[0].size();
        if(m==0||n==0)return false;
        
        for(int i=0;i<m;i++){
            if(bsearch(matrix[i], target))return true;
        }
        
        return false;
    }

    //一维的折半搜索
    bool bsearch(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[mid]>target){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};

//从右上角或者左下角开始
//对于任何一个元素m[i][j]
//向下则大，向左则小(上右同理)
//复杂度为O(m+n)

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m=matrix.size(),n = m==0?0:matrix[0].size();
        if(m==0||n==0)return false;

        //
        int i=0, j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};