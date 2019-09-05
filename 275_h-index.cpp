#include <vector>
#include <algorithm>

using namespace std;

//h index, binary search
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())return 0;
        sort(citations.begin(),citations.end());
        //感觉二分
        int l=0,r=citations.size();
        const int sz=citations.size();
        while(l<r){
            int mid=(l+r)/2;
            int hi=sz-mid;//h-index
            if(hi<=citations[mid]){//满足条件
                r=mid;
            }else{
                l=mid+1;
            }
        }
        //到了这里，l是第一个满足h<=citations[mid]的人
        //但是我们要的是h，所以直接sz-l
        return sz-l;
    }
};