#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int gcd(int m, int n){
    // if(m<n){
    //     return gcd(n,m);
    // }
    // cout<<m<<' '<<n<<'\n';
    if(n==0)return m;
    return gcd(n,m%n);
}


//看了网上的一些结论和答案
//double精度不够，所以上最简分数形式
//还需要避开的坑有正负问题(-1/3 & 1/-3)，所以只要保证分母为正数就行啦
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //计算基于某个点相同斜率的点
        map<pair<int,int>, int> cnt;
        int ans=0;
        for(int i=0;i<points.size();i++){
            int samep=0;//重合
            int verp=0;//垂直
            cnt.clear();
            for(int j=0;j<points.size();j++){
                if(points[i][0]!=points[j][0]){
                    int fa=(points[i][1]-points[j][1]),
                    ch=(points[i][0]-points[j][0]);
                    
                    int gcd_=gcd(fa,ch);
                    fa/=gcd_;
                    ch/=gcd_;
                    if(ch<0){
                        fa=-fa;
                        ch=-ch;
                    }
                    cnt[pair(ch,fa)]++;
                }else if(points[i][1]!=points[j][1]){
                    verp++;
                }else{
                    samep++;
                }
            }
            //
            for(auto it=cnt.begin();it!=cnt.end();it++){
                if(it->second>verp){
                    verp=it->second;
                }
            }
            ans=max(ans,verp+samep);
        }
        return ans;
    }
};