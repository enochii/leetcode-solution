//930. Binary Subarrays With Sum
//连续和还是要想到two sum鸭
//这里的map可以开成数组

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int sum = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int ans = 0;
        for(int i=0;i<A.size();i++){
            sum += A[i];
            
            if(cnt.find(sum-S)!=cnt.end()){
                ans += cnt[sum-S];
            }
            cnt[sum]++;
        }
        
        return ans;
    }
};