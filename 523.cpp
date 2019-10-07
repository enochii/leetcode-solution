// 523. Continuous Subarray Sum

class _Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        
        vector<int> sums(n+1, 0);
        for(int i=0;i<n;i++){
            sums[i+1] = nums[i] + sums[i];
        }
        
        for(int i=0;i<n;i++){
            for(int j = i+2;j<=n;j++){
                if(k==0){
                    if(sums[j]-sums[i]==0)return true;
                }else if((sums[j] - sums[i]) % k == 0){
                    // cout<< i <<' ' << j;
                    return true;
                }
            }
        }
        return false;
    }
    
};

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int n = nums.size();
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            if(k != 0)sum %= k;
            
            auto it = mp.find(sum);
            if(it != mp.end()){
                if(i - it->second > 1) // size >= 2
                    return true;
            }else{
                mp[sum] = i;
            }
        }
        
        return false;
    }
};