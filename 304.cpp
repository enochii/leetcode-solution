// 304. Range Sum Query 2D - Immutable
//看图就行了嗷

//类似range sum，总要有些牺牲者当0

class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return;
        sum.assign(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        //sum[i][j]表示以(0,0)为左上、(i,j)为右下的矩形的总和
        
        for(int i=1;i<=matrix.size();i++){
            int sum_=0;
            for(int j=1;j<=matrix[0].size();j++){
                sum_+=matrix[i-1][j-1];
                sum[i][j]=sum_;
                // if(i!=0){
                sum[i][j]+=sum[i-1][j];
                // }
                // cout<<sum[i][j]<<' ';
            }
            // cout<<'\n';
        }
        //
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(sum.size()==0||sum[0].size()==0)return 0;
        return sum[row2+1][col2+1] + sum[row1][col1] - sum[row2+1][col1] - sum[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */