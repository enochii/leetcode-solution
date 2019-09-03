//感觉主要是技巧吧...
//要求in-place
//这里将每行的首元素或者每列的首元素当成这一列最后是否需要置0的标志
//所以当m[i][j]==0时，要将m[0][j]和m[i][0]置0
//一个点是要注意0...这个刚好标志了行和列
//所以需要额外的辅助位

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col=false,row=false;
        if(matrix.size()==0||matrix[0].size()==0)return;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    if(i==0)row=true;
                    if(j==0)col=true;
                }
            }
        }
        //
        for(int r=1;r<matrix.size();r++){
            if(matrix[r][0]!=0)continue;
            for(int i=1;i<matrix[0].size();i++){
                matrix[r][i]=0;
            }
        }
        //
        for(int c=1;c<matrix[0].size();c++){
            if(matrix[0][c]!=0)continue;
            for(int i=1;i<matrix.size();i++){
                matrix[i][c]=0;
            }
        }
        //(0,0)
        if(matrix[0][0])return;
        if(col)for(int i=1;i<matrix.size();i++)matrix[i][0]=0;
        if(row)for(int i=1;i<matrix[0].size();i++)matrix[0][i]=0;
    }
};