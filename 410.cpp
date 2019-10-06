// 410. Split Array Largest Sum

class _Solution {
    //二分
    //Time Complexity: O(log(Sum-max) * n)
public:
    typedef long type;
    int splitArray(vector<int>& nums, int m) {
        //tmd，好多东西都可以上BS
        //reference : https://blog.csdn.net/mebiuw/article/details/52724293
        
        
        int maxi = INT_MIN;
        type sum = 0;
        
        for(int num:nums){
            maxi = max(maxi, num);
            sum += num;
        }
        
        //二分
        type left = maxi, right = sum + 1ll;
        while(left < right){
            type mid = left + (right - left)/2;
            if(valid(nums, mid, m)){
                right = mid;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    bool valid(vector<int>& nums, long long max,int m){
        int cnt = 0;
        type cur = 0;
        for(int num:nums){
            cur += num;
            if(cur > max){
                cur = num;
                if(++cnt >= m){
                    return false;
                }
            }
        }
        return true;
    }
};

// 还有个dp版本的
// dp[i][j]表示前j个数字划分成i个子序列，minimize所有子序列和的最大值所得到的最小值
// val = max(dp[i-1][k], nums[k]+nums[k+1]+...+nums[j-1])
// dp[i][j] = min{val} for k>=i-1

class Solution {
    //DP
    //Time Complexity: O(n^3)?
public:
    typedef long type;
    int splitArray(vector<int>& nums, const int m) {
        const int n = nums.size();
        
        vector<type> sums(n + 1, 0);
        for(int i=0;i<n;i++){
            sums[i+1] = sums[i] + nums[i];
        }
        
        vector<vector<type>> dp(m+1,vector<type>(n+1, INT_MAX));
        
        dp[0][0] = 0;//
        for(int i=1;i<=m;i++){
            for(int j=i;j<=n;j++){
                for(int k=i-1;k<=j;k++){
                    //前j个数分成i组可以是：前k个数分成i-1组，剩下的自称一组
                    type val = max(dp[i-1][k], sums[j] - sums[k]);//[k, j-1]
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[m][n];
    }
};