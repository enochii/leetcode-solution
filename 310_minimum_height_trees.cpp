#include <vector>
#include <queue>

using namespace std;

//degree, mimimum height tree, MHT
class Solution {
    //只要求出某个点到所有点的路径，最长的就是那个高度
    //在这些高度找minimum的高度即可，不过这样需要求所有点之间的最短路径
    //还有一种简单的思路是求最长链的中点
    //可以转化成类似拓扑剪点的操作
    
    //wdnmd还得自己改函数声明
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0)return {};
        if(n==1)return {0};
        if(n==2)return {0,1};
        vector<int> in(n,0);//入度数组
        vector<vector<int>> nb(n);//neighborhood -> 邻接矩阵
        //这nm是个无环图，所以一条边会给两个点的入度+1
        for(auto& p:edges){
            in[p[0]]++;
            in[p[1]]++;
            //
            nb[p[0]].push_back(p[1]);
            nb[p[1]].push_back(p[0]);
        }
        vector<bool> vis(n,false);
        //这个队列记录入度为1的点，也就是叶节点
        queue<int> q;
        int count=n;
        for(int i=0;i<n;i++){
            if(in[i]==1){
                count--;
                q.push(i);
                vis[i]=true;
                // cout<<i;
            }
        }
        //这个要有层次的pop和push
        // cout<<n;
        while(!q.empty()){
            if(count==1||count==2)break;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int top=q.front();q.pop();
                // ans.push_back(top);
                for(int& x:nb[top]){
                    if(--in[x]==1){
                        q.push(x);
                        vis[x]=true;
                        count--;
                    }
                }
                
            }
            //
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==false)ans.push_back(i);
        }
        return ans;
    }
};