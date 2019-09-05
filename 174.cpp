#include <vector>
#include <algorithm>

using namespace std;

//dfs dp
//Minimum Health

//日，虽然用了带记忆化的dfs，但其实是可以写成迭代的dp的！

//首先只有两个方向
//然后就是dfs了，一个点是注意后面的血量为正对前面没啥用
//并且答案必然大于1... 开头就可以加血也没用
static int dir[3]={1,0,1};
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //注意起始和终止都可能有+-血条
        //初始血量应该是行进过程中出现的最大负数+1...


        //minh[i][j]表示从该点出发需要的最小血量（的相反数）
        vector<vector<int>> minh(dungeon);
        vector<vector<bool>> vis(dungeon.size(),vector<bool>(dungeon[0].size(),false));
        // minh.back().back()=dungeon.back().back();
        vis.back().back()=true;
        if(dungeon.size()==0||dungeon[0].size()==0)return 0;
        int res=dfs(0,0,dungeon,vis,minh);
        
        // for(auto&d:minh){
        //     for(auto i:d){
        //         cout<<i<<' ';
        //     }
        //     cout<<'\n';
        // }
        //我还特意把0和正数分开，原来没必要...
        //像[[100]]结果是1
        return res>=0?1:-res+1;
    }
    //
    int dfs(int x, int y, vector<vector<int>>& dungeon,vector<vector<bool>> &vis,
        vector<vector<int>>& minh
    ){
        if(vis[x][y]){
            return minh[x][y];
        }
        //
        vis[x][y]=true;
        int maxv=INT_MIN;//最小的负数
        for(int i=0;i<2;i++){
            int nx=x+dir[i];
            int ny=y+dir[i+1];
            if(nx<0||ny<0||nx>=dungeon.size()||ny>=dungeon[0].size())continue;
            int res=dfs(nx,ny,dungeon,vis,minh);
            res=min(res,0);//血量不能往前累加
            maxv=max(res,maxv);
        }

        maxv+=dungeon[x][y];
        return minh[x][y]=maxv;
    }
};

//拷了下别人的代码
//dp的顺序还是有点秀的
/*

int calculateMinimumHP(vector<vector<int>>& a) {
        if (!a.size() || !a[0].size()) {
            return 1;
        }
        const int rows = a.size();
        const int cols = a[0].size();

        int64_t dp[cols + 1];
        for (int c = cols; c >= 0; c--) {
            dp[c] = INT_MAX;
        }
        dp[cols - 1] = 1;

        constexpr int64_t min_need = 1;

        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                const int64_t v = a[r][c];
                dp[c] = max(min_need, min(dp[c], dp[c + 1]) - v);
            }
        }

        return dp[0];
    }

*/