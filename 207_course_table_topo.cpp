#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //操! 拓扑排序!
    //做成邻接链表而不是布尔矩阵好像会稍微省空间且快点
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        // for(int i=0;i<pre.size();i++){
        //     n=max(pre[i][1]+1,n);
        // }
        //
        vector<vector<int>> tb(n,vector<int>());
        for(int i=0;i<pre.size();i++){
            tb[pre[i][1]].push_back(pre[i][0]);
        }
        vector<int> vis(n, 0);
        //0->未访问
        //1->已访问
        //2->正在被访问
        for(int i=0;i<n;i++){
            if(!dfs(i,tb,vis))return false;
        }
        return true;
    }

    bool dfs(int i,vector<vector<int>>& tb, vector<int>& vis){
        if(vis[i]==2)return false;
        if(vis[i]==1)return true;
        //
        vis[i]=2;
        for(int j=0;j<tb[i].size();j++){
            if(!dfs(tb[i][j],tb,vis))return false;
        }
        vis[i]=1;
        return true;
    }
};