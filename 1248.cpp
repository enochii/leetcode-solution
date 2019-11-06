// 1248. Count Number of Nice Subarrays
//Sliding Window

//转化成奇数小于等于k的问题
//equals(k) = atMost(k) - atMost(k-1)
//感觉那个内层循环算包含end的sub-array还是有点牛逼的
class _Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
    
    int atMostK(vector<int>& nums, int k)
    {
        const int n = nums.size();
        int start = 0;
        int ans = 0;
        
        int sum = 0;
        for(int end = 0;end < n; end++)
        {
            k -= nums[end]%2;
            
            while(k < 0)
            {
                k+=nums[start++]%2;
            }
            //**包含end**的sub-array且小于k的总共是end - start + 1
            ans += end - start+1;
        }
        
        return ans;
    }
};

//无脑滑窗
//先划一个窗口[start, end]，满足k个奇数
//取pend = end
//递增end到end+1所在位置是一个奇数
//这时候算出end - pend + 1

//递增start到满足和为k-1
//在过程中继续+(end - pend +1)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        const int n = nums.size();
        
        int start = 0, end = 0;
        int ans = 0;
        
        int sum = 0;
        
        while(end < n)
        {
            sum += nums[end]%2;
            
            if(sum == k)
            {
                int pend = end;
                while(end+1 < n && nums[end+1]%2 == 0)
                {
                    end ++;
                }
                ans += end - pend+1;
                //start inc
                int pstart = start;
                while(start < end && nums[start] %2 ==0)
                {
                    ans += end - pend+1;
                    start++;
                }
                sum -= 1;
                start++;
            }
            end++;
        }
        return ans;
    }
};

//TLE

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         //
//         const int n = nums.size();
        
//         vector<int> cnt(n+1, 0);
//         int cur = 0;
//         for(int i=0;i<n;i++)
//         {
//             cur += (nums[i] % 2 == 1);
//             cnt[i+1] = cur;
//             // cout << cnt[i+1] <<' ';
//         }
//         // cout <<'\n';
        
//         int ans = 0;
//         for(int i=0;i<n;i++)
//         {
//             //计算以i开始的nice-array
//             int j;
//             for(j=i+1;j<=n;j++)
//             {
//                 if(cnt[j] - cnt[i] == k)break;
//             }
            
//             int end = j;
//             for(;end<=n;end++)
//             {
//                 if(cnt[end] - cnt[i] > k)break;
//             }
//             // cout << i << ' ' << j << ' ' << end << '\n';
//             ans += end - j;
//         }
//         return ans;
//     }
// };