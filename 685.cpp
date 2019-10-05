// 685. Redundant Connection II
//reference: https://www.acwing.com/solution/LeetCode/content/4124/

#include <vector>
#include <iostream>

using namespace std;

//存在入度为2的点
//或者存在环
//或者两者皆有

//如果只存在环，那么用并查集就可以直接搞定
//如果存在入度为2单独拉出来讨论
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        const int n = edges.size();
        
        //用来装两个爹
        vector<int> tmp;
        tmp.reserve(2);
        
        vector<int> in(n, 0);
        for(auto& edge: edges){
            ++in[edge[1]-1];
        }
        
        vector<int> fa(n+1, 0);
        for(int i=0;i<n;i++)fa[i+1]=i+1;
        
        int child = -1;
        for(auto &edge:edges){
            int x = edge[0], y = edge[1];
            if(in[y-1]==2){
                tmp.push_back(x);
                child = y;
                continue;
            }
            
            int fax = find(fa, x);
            int fay = find(fa, y);
            
            if(fax == fay)return edge;
            fa[fax] = fay;
        }
        
        //必定是入度为2
        //检测是否是入度为2且有环
        //如果第一个无环，那么只可能是第二个有环或者本来就没环。按照题目要求选慢出现的
        int fac = find(fa, child);
        int fa1 = find(fa, tmp[0]);
        if(fa1 == fac)return {tmp[0], child};
        else return {tmp[1], child};
    }
    
    int find(vector<int>& fa, int c){
        if(fa[c] != c)fa[c] = find(fa, fa[c]);
        return fa[c];
    }
};