// 407. Trapping Rain Water II

class Solution {
public:
    //思路跟一维的很像，不过要上堆，反正我想不出来
    //就是保持一个边界，未访问的节点在边界之中
    //每次拿一个最低的节点出来做BFS，从而形成一个新的边界
    
    //还会维持一个curMinBorder，它是某个边界的最小点，代表一个边界(木桶效应)
    //在更新边界的过程中，我们尽量使这个值最大，也即是最有用的边界
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int r = heightMap.size();
        const int c = r==0?0:heightMap[0].size();
          
        if(r < 3 || c < 3)return 0;
        
        multimap<int, pair<int,int> > mp;
        vector<vector<int>> vis(r, vector(c, 0));
        
        
        //先把四周边界围进来
        for(int i=0;i<c;i++){
            mp.emplace(heightMap[0][i], make_pair(0, i));
            mp.emplace(heightMap[r-1][i], make_pair(r-1, i));
            vis[0][i] = 1;
            vis[r-1][i] = 1;
        }
        
        for(int i=1;i<r-1;i++){
            mp.emplace(heightMap[i][0], make_pair(i, 0));
            mp.emplace(heightMap[i][c-1], make_pair(i, c-1));
            vis[i][0] = 1;
            vis[i][c-1] = 1;
        }
        //
        int dir[] = {1,0,-1,0,1};
        
        //对于未访问的节点而言，当前的最小边界
        int curMinBorder = INT_MIN;
        int ans = 0;
        while(mp.size()){
            auto mini = mp.begin();
            
            curMinBorder = max(curMinBorder, mini->first);
            
            int x = mini->second.first;
            int y = mini->second.second;
            
            mp.erase(mini);
            
            for(int i=0;i<4;i++){
                int nx = x + dir[i];
                int ny = y + dir[i+1];
            
                if(nx < 0 || nx >= r || ny < 0 || ny >= c || vis[nx][ny])continue;

                int nh = heightMap[nx][ny];
                if(curMinBorder > nh){
                    ans += curMinBorder - nh;
                }
                vis[nx][ny] = 1;
                mp.emplace(heightMap[nx][ny], make_pair(nx, ny));
            }
        }
        
        return ans;
    }
};


//错了...
//还可能从旁边流出去，要上DP估计


// class Solution {
// public:
//     int trapRainWater(vector<vector<int>>& heights) {
//         //分列、分行扫描
//         //再对每个点的两个结果取最小
//         const int r = heights.size(), c = heights.empty()? 0 : heights[0].size();
//         if(r<=2||c<=2)return 0;
        
//         vector<vector<int>> water(heights.size(), vector<int>(heights[0].size(), 0));
        
//         //行
//         for(int i=1;i<r-1;i++){
//             int lmax = heights[i][0], rmax = heights[i][c-1];
//             //
//             int l=1, r=c-2;
//             while(l<=r){
//                 if(lmax < rmax){
//                     //l最多只能lmax！
//                     if(lmax > heights[i][l]){
//                         water[i][l] = lmax;
//                     }else{
//                         lmax = heights[i][l];
//                     }
//                     l++;
//                 }else{
//                     if(rmax > heights[i][r]){
//                         water[i][r] = rmax;
//                     }else{
//                         rmax = heights[i][r];
//                     }
//                     r--;
//                 }
//             }
//         }
//         int ans = 0;
//         //列
//         for(int j=1;j<c-1;j++){
//             int umax = heights[0][j], dmax = heights[r-1][j];
            
//             int u = 1, d = r - 2;
//             while(u <= d){
//                 if(umax < dmax){
//                     if(umax > heights[u][j]){
//                         int wa = min(water[u][j], umax) - heights[u][j];
//                         if(wa>0)cout<<u<<' '<<j<<' '<<wa<<'\n';
//                         ans += max(0, wa);
//                     }else{
//                         umax = heights[u][j];
//                     }
//                     u++;
//                 }else{
//                     if(dmax > heights[d][j]){
//                         int wa = min(water[d][j], dmax) - heights[d][j];
//                         if(wa>0)cout<<d<<' '<<j<<' '<<wa<<'\n';
//                         ans += max(wa, 0);
//                     }else{
//                         dmax = heights[d][j];
//                     }
//                     d--;
//                 }
//             }
//         }
//         return ans;
//     }
// };