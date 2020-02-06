class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // 先按行扫描，若出现落单的 server 则做标记
        
        // 按列扫扫描，若出现落单的 server 再做一层标记
        
        // 只会对 有server的格子 做标记，出现两层标记才认为是 unconnected的
        
        //用总数减去即可
        
        const int m = grid.size();
        const int n = m?grid[0].size():0;
        if(!m || !n)return 0;
        
        //server  总数
        int server_cnt = 0;
        for(auto& row:grid)
        {
            for(int s:row)
            {
                server_cnt += s;
            }
        }
        
        //按行扫描
        for(int i=0;i<m;i++)
        {
            int first = -1;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)continue;
                if(first == -1)
                {
                    first = j;
                }else{
                    //不止一个 server
                    first = -1;
                    break;
                }
            }
            if(first != -1)
            {
                //标记
                grid[i][first] = -1;
            }
        }
        
        int unconnected = 0;
        //按列扫描
        for(int j = 0;j<n;j++)
        {
            int first = -1;
            
            for(int i=0;i<m;i++)
            {
                if(grid[i][j] == 0)continue;
                if(first == -1)
                {
                    first = i;
                }
                else{
                    first = -1;
                    break;
                }
            }
            //行列都没人要，孤儿
            if(first != -1 && grid[first][j] < 0)
            {
                unconnected ++;
            }
        }
        
        //获得 connected 的server数量
        return server_cnt - unconnected;
    }
};