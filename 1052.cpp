// 1052. Grumpy Bookstore Owner
//Sliding Window
//我居然想出来了？！
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int x) {
        //滑动窗口（X）求最大的潜在损失
        const int n = customers.size();
        if(x >= n)return accumulate(customers.begin(), customers.end(), 0);
        
        int start = 0, end = 0;
        int loss = 0;
        for(;end < x;end++){
            loss += grumpy[end]? customers[end] : 0;
        }
        
        int maxLoss = loss, maxStart = 0;
        while(end < n){
            loss -= grumpy[start]? customers[start]:0;
            start++;
            
            loss += grumpy[end]? customers[end]:0;
            end++;
            
            if(maxLoss < loss){
                maxLoss = loss;
                maxStart = start;
            }
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!grumpy[i] || (i >= maxStart && i < maxStart + x)){
                ans += customers[i];
            }
        }
        return ans;
    }
};