class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        //分情况讨论就行
        //k == 0 -> 0
        //k == 1 -> 转化成Maximum Sum问题
        //k >=2  -> Maximum Sum是候选 最大后缀+最大前缀+(sum_all > 0 ? (k-2):0)*sum_all
        
        //初步想法是计算一个最大数组后缀和最大前缀
        //再看整个数组的和是正还是负决定要不要把中间的(k-2)个完整数组加进去
        
        // vector<int> has_beg(arr.size(), 0);
        // vector<int> has end(arr.size(), 0);
        if(k == 0)return 0;
        int single_sum = maxSum(arr);
        if(k == 1)return single_sum;
        
        const int sz = arr.size();
        
        int sum = 0;
        int rsum = 0;// reverse order sum
        
        int has_beg = 0, has_end = 0;
        
        for(int i=0;i<sz;i++){
            sum += arr[i];
            has_beg = max(has_beg, sum);
            
            rsum += arr[sz - 1 - i];
            has_end = max(has_end, rsum);
        }
        
        int candi = (long long)has_beg+has_end+ ((sum>0?(k-2):0)*(long long)sum % (1000000007));
        
        return max(single_sum, candi
                  );
    }
    
    int maxSum(vector<int> & arr){
        // if(arr.empty())return 0;
        int ans = 0;
        
        int sum = ans;
        //dp[i] = max(dp[i-1]+arr[i], arr[i])
        for(int i=0;i<arr.size();i++){
            if(sum<0){
                sum = arr[i];
            }else{
                sum += arr[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};