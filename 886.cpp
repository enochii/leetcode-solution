// 886. Possible Bipartition
class Solution {
    //染色问题，最多只能由两种色
    //如果直接读边染色，当遇到[[1,2], [3,4], ..]
    //3事实上你不知道应该染什么色，因为你并没有足够的信息
    //所以通过邻接矩阵，你到了某个点，只需要把邻接的点全部的点染成相反的色即可
    //dfs和bfs均可
    
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        if(N <= 2 || dislikes.size() < 2)
        {
            return true;
        }
        //染色问题
        vector<int> color(N, -1);
        vector<vector<int>> gra(N, vector<int>(N, 0));
        for(auto & dis:dislikes)
        {
            gra[dis[0]-1][dis[1]-1] = 1;
            gra[dis[1]-1][dis[0]-1] = 1;
        }
        
        for(int i=0;i<N;i++)
        {
            //这种形式其实有点像连通分量那一套
            //因为不同连通分量事实上是不互相影响的
            //所以起始点染0/1是无所谓的
            if(color[i] != -1)continue;
            // cout << "!";
            color[i] = 0;
            if(!dfs(i, gra,color, 1))
            {
                // for(int j = 0;j<gra.size();j++)
                // {
                //     cout << color[j] <<' ';
                // }
                return false;
            }
        }
        
        
        return true;
    }
    
    //出现错误时返回false
    //再返回值卡了好久........
    //做成非递归的做法可以从300+ms -> 100+ms?
    //建议bfs
    bool dfs(int src, vector<vector<int>>& gra, vector<int>& color, int col)
    {
        for(int i=0;i<gra.size();i++)
        {
            if(gra[src][i] == 0)continue;
            
            if(color[i] != -1)
            {
                // cout << src << ' ' << i << ' '<<col <<' '<<color[i]<<'\n';
                if(color[i] != col)return false;
                else continue;
            }
            color[i] = col;
            if(!dfs(i,gra,color,!col))return false;
        }
        
        return true;
    }
};