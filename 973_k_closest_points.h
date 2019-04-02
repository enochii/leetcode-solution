#include <algorithm>

struct{
    bool operator()(std::vector<int>& l,std::vector<int>& r)
    {
        return (l[0]*l[0]+l[1]*l[1])
                <(r[0]*r[0]+r[1]*r[1]);
    }
}less_;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //理论上这样会对每个点到原点的距离做许多次重复运算
        std::sort(points.begin(),points.end(),less_);

        int remove_cnt = points.size()-K;
        // std::cout<<remove_cnt<<"\n";
        while(remove_cnt-->0){
            points.pop_back();
        }
        return points;
    }
};