// 123. Best Time to Buy and Sell Stock III

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //最多只能做两次交易
        //把两次交易直接划分下
        //也就是说，找一个划分点，这样两次交易就不会重叠
        
        if(prices.empty())return 0;

        int minpri=prices[0];
        vector<int> maxpro(prices.size(),0);
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minpri){
                minpri=prices[i];
            }
            // else{
                maxpro[i]=max(prices[i]-minpri, maxpro[i-1]);
            // }
        }
        // for(auto p:maxpro)cout<<p<<' ';
        //
        int ans=0;

        int maxpri=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>maxpri){
                maxpri=prices[i];
            }else{
                //同一天卖出买入相当于只做了一次交易
                ans=max(ans,maxpri-prices[i]+maxpro[i]);
                // cout<<i<<' '<<maxpri<<' '<<maxpro[i]<<'\n';
            }
        }
        return ans;
    }
};