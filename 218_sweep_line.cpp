#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//可以把multiset当成优先队列用

//这道题用的手法叫啥扫描法
//大概下次遇到这种题还是不会--
//事实上可以发现相邻的两个kepoints是直角的两个点
//我们把一个矩形拆成两个顶点
//当最大高度发生变化就要加入一个keypoint

//小trick有 左顶点进入points数组高度标成负数，右顶点标成正数
//这除了区分左右外还有一个点是排序...
//如果有多个点x相同y不同的情况，考虑两个点的情况 -> 又有4种情况 左左 左右 右右 左左
//原则是左顶点在前 然后如果都是右顶点那就是从低到高 左顶点从高到低 避免不必要的关键点
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> hts;
        vector<pair<int,int> > points;
        for(int i=0;i<buildings.size();i++){
            points.emplace_back(buildings[i][0],-buildings[i][2]);//tmd左顶点
            points.emplace_back(buildings[i][1],buildings[i][2]);//tmd右顶点
        }
        sort(points.begin(),points.end());
        //
        vector<vector<int> > ans;
        hts.insert(0);//天杀的0...
        int max_height=0;
        for(auto& point:points){
            if(point.second<0){
                hts.insert(-point.second);
            }else{
                //>0
                //只能删除一个，早入队的那个
                hts.erase(hts.find(point.second));
            }
            //最大高度是否发生了改变
            if(max_height!=*hts.rbegin()){
                max_height=*hts.rbegin();
                ans.push_back({point.first,max_height});
            }
        }
        return ans;
    }
};