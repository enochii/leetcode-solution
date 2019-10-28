// 733. Flood Fill
//dfs
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int color) {
        int oldCol = image[r][c];
        if(color != oldCol)dfs(image,r,c,color,oldCol);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int color, int oldCol){
        static int dir[5] = {1,0,-1,0,1};
        
        image[r][c] = color;
        for(int i=0;i<4;i++){
            int x = r + dir[i];
            int y = c + dir[i+1];
            
            if(x < 0 || y < 0 
               || x >= image.size() || y >= image[0].size()
              || image[x][y] != oldCol)//涂色的也可以通过这个判断
                continue;
            
            dfs(image,x,y,color,oldCol);
        }
    }
};