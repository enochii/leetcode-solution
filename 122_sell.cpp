class _Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int sz=prices.size();
        
        if(sz<2)return 0;
        //多阶段决策
        //感觉上dp吧，因为在某一天只要状态确定那就对不会对后来的决策产生影响
        //0表示当前有货，1表示当前无货
        //dp[i][1]=max(dp[i-1][0]+p[i],dp[i-1][1])
        //dp[i][0]=max(dp[i-1][1]-p[i],dp[i-1][0])
        vector<vector<int>> dp(sz,vector<int>(2,0));
        dp[0][0]=-prices[0];
        dp[0][1]=0;
        for(int i=1;i<prices.size();i++){
            dp[i][0]=max(dp[i-1][1]-prices[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
        }
        return dp[sz-1][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)return 0;
        //可以贪心
        //感觉有点变治法的味道
        //就是在同一天买入和售出是不被允许的
        //但是事实上它是无意义的，允许它也不会对结果产生影响
        //那么可以想象购买和收入的两个点之间(包括两端)
        //事实上一定是单调递增的
        //可以证明如果不是单调递增可以找到更优的方案(可以想象价格的趋势线)
        //我们换一种状态表达
        //每次交易作为一次转换，只要相邻两天价格上升就加到利润里面
        int sum=0;
        for(int i=1;i<prices.size();i++){
            sum=max(sum,sum+prices[i]-prices[i-1]);
        }
        //我感觉好像想到不太严格的证明手法了
        //就是整个价格趋势一定是一条波浪线的子集
        //容易得出结论：把那些上升段的长度加起来就是最大利润
        //否则会减少利润
        //我不要你觉得，都听我的
        return sum;
    }
};