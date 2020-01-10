// 566. Reshape the Matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int r0 = nums.size();
        int c0 = r0>0?nums[0].size():0;
        
        if(r0*c0 != r * c){
            return nums;
        }
        
        vector<vector<int>> res(r, vector<int> (c));
        
        for(int i=0;i<r0;i++)
        {
            for(int j=0;j<c0;j++)
            {
                int index = i*c0+j;
                res[index / c][index % c] = nums[i][j];
            }
        }
        
        return res;
    }
};