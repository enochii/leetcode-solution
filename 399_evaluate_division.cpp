#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

// 做完预处理就是个dfs，很不熟练的dfs
// 数据格式别搞错...貌似DFS和dfs是为了加个visited？


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, int> s2d;
        int cnt = 0;
        for(auto p:equations){
            for(int i=0;i<2;i++){
                if(!s2d.count(p[i])){
                    s2d[p[i]] = cnt++;
                }
            }
        }
        vector<vector<double> > paths(cnt, vector<double>(cnt, -2.0));
        for(int i=0;i<equations.size();i++){
            auto  p=equations[i];
            int p0 = s2d[p[0]], p1 = s2d[p[1]];

            double val = values[i];
            paths[p0][p1] = val;
            if(val!=0.0){
                paths[p1][p0] = 1.0/val;
            }
        }
        for(int i=0;i<cnt;i++){
            paths[i][i] = 1.0;
        }
        // cout<<paths[0][1]<<'\n';
        //预处理完成
        vector<double> ret;
        for(auto p:queries){
            if(!s2d.count(p[0])||!s2d.count(p[1])){
                ret.push_back(-1.0);
            }
            else if(p[0]!=p[1]){
                ret.push_back(DFS(s2d[p[0]],s2d[p[1]],paths));
            }else{
                ret.push_back(1.0);
            }
        }
        return ret;
    }
    //
    double DFS(int a, int b, vector<vector<double> >& paths){
        vector<int> visited(paths.size(), 0);
        visited[a] = true;
        return dfs(a,b,paths,visited);
    }

    double dfs(int a, int b, vector<vector<double> >& paths, vector<int>& vis){
        if(paths[a][b]!=-2.0){
            // cout<<a<<' '<<b<<' '<<paths[a][b]<<'\n';
            return paths[a][b];
        }
        //
        
        for(int i=0;i<paths.size();i++){
            if(vis[i])continue;
            double cost = paths[a][i];
            if(cost<0.0)continue;//暂时没路
            // if(i==a)continue;//本身不搜索
            vis[i] = true;
            double res = dfs(i, b, paths, vis);
            vis[i] = false;
            if(res==-1.0)continue;//死路
            // cout<<a<<' '<<i<<' '<<b<<' '<<res<<'\n';
            // cout<<cost<<' '<<res<<'\n';
            return cost*res;
        }
        return -1.0;
    }
};

int main(){
// [["a","b"],["b","c"],["bc","cd"]]
// [1.5,2.5,5.0]
// [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]

    vector<vector<string> > eqs = {{"a","b"},{"b","c"},{"c","b"},{"b","e"}};
    vector<double> values = {1.5, 2.5, 5.0, 0.5};
    vector<vector<string> > qus = {{"a","e"}};

    cout<<Solution().calcEquation(eqs,values, qus)[0];

    return 0;
}