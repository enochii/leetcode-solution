#include <vector>

using namespace std;

class _Solution {
public:
    //判断是否无环，并且把拓扑序返回
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int n=numCourses;
        vector<int> in(n,0);
        for(int i=0;i<prerequisites.size();i++){
            in[prerequisites[i][0]]++;
        }
        //
        vector<int> ans;
        while(1){
            int min_i=-1;
            for(int i=0;i<n;i++){
                if(!in[i]){
                    min_i=i;
                    break;
                }
            }
            if(min_i==-1)return {};
            ans.push_back(min_i);
            if(ans.size()==n)break;
            in[min_i]=n+1;
            for(int i=0;i<prerequisites.size();i++){
                if(prerequisites[i][1]==min_i){
                    in[prerequisites[i][0]]--;
                }
            }
        }
        return ans;
    }
};

//这个解决topo的思路感觉不错
//多用了个二维存储某课程的后置课程，以便后面减去入度为0的点可以快速对后置课程的入度--
//在--的过程中，顺手也把入度为0的点弄进候选队列，感觉思路很巧
class Solution {
public:
    //判断是否无环，并且把拓扑序返回
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> rec(numCourses);//rec[i]存储以i作为前置课程的所有课程
        vector<int> in(numCourses,0);//入度
        for(auto& pre:prerequisites){
            rec[pre[1]].push_back(pre[0]);
            in[pre[0]]++;
        }

        //
        vector<int> heads;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                heads.push_back(i);
            }
        }

        vector<int> ans;
        while(!heads.empty()){
            int h=heads.back();
            heads.pop_back();
            for(int i=0;i<rec[h].size();i++){
                if(--in[rec[h][i]]==0){
                    heads.push_back(rec[h][i]);
                }
            }
            ans.push_back(h);
        }
        return ans.size()==numCourses?ans:vector<int>{};
    }
};