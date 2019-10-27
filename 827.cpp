//827. Making A Large Island

//第一遍先求出所有的连通分量并且打上tag
//第二遍扫0，也就是所有合法变1的位置
//算出在当前位置填上1可以连接的最大节点数（记得去重）

class Solution {
    typedef vector<vector<int>> vvi;
    int m,n;
public:
    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = m?grid[0].size() : 0;
        if(!m || !n)return 0;
        
        int tag=0;
        //对应的tag的节点数量
        unordered_map<int,int> tagCnt;
        vvi tags(m,vector<int> (n,-1));
        
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && tags[i][j] == -1){
                    int tmp = tagCnt[tag] = dfs(tags,grid,tag,i,j);
                    ans = max(tmp, ans);
                    
                    // cout << tag << ' ' << tagCnt[tag]<<'\n';
                    tag++;
                }
            }
        }
        
        // tagCnt[-1] = 0;
        unordered_set<int> st;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    //
                    int tmp = 0;
                    for(int d=0;d<4;d++){
                        int x = i + dir[d];
                        int y = j + dir[d+1];
                        
                        if(!valid(x,y) || 0==grid[x][y] || tags[x][y] == -1)continue;
                        st.insert(tags[x][y]);
                    }
                    for(int ta:st){
                        tmp += tagCnt[ta];
                    }
                    st.clear();//没有clear都能过快一半？
                    ans = max(ans, tmp+1);
                    //
                }
            }
        }
        return ans;
    }
private:
    int dir[5] = {1,0,-1,0,1};
    //
    int dfs(vvi& tags, vvi& grid, int tag, int r, int c){
        if(!valid(r,c) || //越界
           tags[r][c] >= 0 || //已经访问
           grid[r][c] == 0 //过不去
          )return 0;
        
        tags[r][c] = tag;
        int ans = 1;
        
        for(int i=0;i<4;i++){
            int x = r + dir[i];
            int y = c + dir[i+1];
            
            ans+=dfs(tags,grid,tag,x,y);
        }
        // cout<<ans<<' ';
        return ans;
    }
    
    bool valid(int r, int c){
        return !(r < 0 || c < 0 || r >= m || c >= n);
    }
};