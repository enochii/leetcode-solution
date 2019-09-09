// 120. Triangle

#include <vector>
#include <algorithm>

//DP
//印象里紫书好像有--

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())return 0;
        for(int i=triangle.size()-1;i>0;i--){
            const int cnt=i;//cnt of current level
            for(int j=0;j<cnt;j++){
                triangle[i-1][j]+=min(triangle[i][j],
                triangle[i][j+1]);
            }
        }
        return triangle.front().front();
    }
};
