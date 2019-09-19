#include <map>
#include <vector>

using namespace std;

//顺序计数，数到W
//数不到就直接拘留
//否则数到cnt为空
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> cnt;
        for(int num: hand){
            cnt[num]++;
        }
        //
        while(!cnt.empty()){
            auto it =cnt.begin();
            int tmp=0;
            do{
                tmp++;
                int next=it->first+1;
                if(--it->second==0){
                    cnt.erase(it);
                }
                it=cnt.find(next);
            }while(it!=cnt.end()&&tmp<W);
            if(tmp!=W)return false;
        }
        return true;
    }
};