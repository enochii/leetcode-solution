#include <vector>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(const vector<int>& a, const vector<int>& b){
        return a[0]>b[0] || (a[0]==b[0]&&a[1]<b[1]);
    }
};

//矮的人对高的人没影响...
//所以可以按照cmp先排序
//这样相同高度之间的相对序就是不变的
//接下来从矮到高进行调整
//交换手法跟插入排序有点类似？
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.empty())return people;
        sort(people.begin(),people.end(),cmp());

        int cur = people[0][0];
        int i=1;
        while(i<people.size()&&people[i][0]==cur)i++;
        if(i>=people.size())return people;
        cur = people[i][0];
        while(true){
            for(;i<people.size()&&people[i][0]==cur;i++){
                int pos = people[i][1];
                for(int j=i;j>pos;j--){
                    swap(people[j],people[j-1]);
                }
            }
            if(i>=people.size()){
                break;
            }else{
                cur=people[i][0];
            }
        }

        return people;
    }
};