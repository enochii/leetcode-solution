#include <vector>
#include <unordered_map>

using namespace std;

//想法是分别枚举A+B 和 C+D
//用一个map存计算A+B的结果
//计算C+D时在map里面搜就行
//时间复杂度如果把map的搜索看成常数应该是O(n*n)
//如果看成对数，那么应该是O(n^2 logn)

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto a:A){
            for(auto b:B){
                mp[a+b]++;
                // cout<<mp[a+b]<<a+b<<' ';
            }
        }
        for(auto c:C){
            for(auto d:D){
                int exp=-(c+d);
                if(mp.count(exp)){
                    ans+=mp[exp];
                }
            }
        }
        return ans;
    }
};