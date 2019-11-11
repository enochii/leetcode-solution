//992. Subarrays with K Different Integers

// //用朴素的 滑窗好像有点难

// // class Solution {
// // public:
// //     int subarraysWithKDistinct(vector<int>& A, int K) {
// //         unordered_map<int, int> cnt;
        
// //         int width = 0;//窗口当前的宽度
// //         for(int num:A)
// //         {
// //             auto it = cnt.find(num);
// //             if(it == cnt.end())
// //             {
// //                 //即将超过窗口限度 K
// //                 if(++cnt == K)
// //                 {
                    
// //                 }
// //             }else{
                
// //             }
// //         }
// //     }
// // };

//纪念自己又臭又长的代码，还一堆bug--


// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& A, int K) 
//     {
//         int k= atMostK(A, K) , km = atMostK(A, K-1);
        
//         cout << k <<' '<<km;
//         return k-km;
//     }
    
//     int atMostK(vector<int> & arr, int K)
//     {
//         cout <<"\n====="<< K <<"=====\n";
//         unordered_map<int ,int> cnt;
        
//         int start = 0, end = 0;
//         int curK = 0;
        
        
//         while(end < arr.size() && curK < K)
//         {
//             if(cnt.find(arr[end]) == cnt.end())
//             {
//                 curK ++;
//             }
            
//             cnt[arr[end++]]++;
//         }
//         //= K后疯狂扩张
//         while(end < arr.size() && cnt.find(arr[end])!=cnt.end())
//         {
//             cnt[arr[end++]]++;
//         }
        
        
//         int ans = 0;
//         for(;end < arr.size();end++)
//         {
//             //现在start -> end刚好是k
//             ans += end - start;//以start开始的所有合法subarray
//             cout << " (" <<end << ", "<< start <<") ";
//             start++;
//             while(start < end && --cnt[arr[start-1]] > 0)
//             {
//                 // start++;
//                 ans += end - start;//
//                 cout << " (" <<end << ", "<< start <<") ";
//                 start++;
//             }
            
//             cnt.erase(arr[start++]);//变成K-1
//             curK--;
//             while(end < arr.size() && cnt.find(arr[end]) != cnt.end())
//             {
//                 ++cnt[arr[end++]];
//             }
//             if(end >= arr.size())break;
//             ++cnt[arr[end++]];// 变成K
//             curK++;
//             while(end < arr.size() && cnt.find(arr[end]) != cnt.end())
//             {
//                 ++cnt[arr[end++]];
//             }
//             if(end == arr.size())break;
//         }
        
        
//         int len = end - start;
//         cout << " (" <<end << ", "<< start <<") ";
//         cout << len * (len + 1)/2<<' ';
//         ans += len * (len + 1)/2;
        
//         return ans;
//     }
// };


//
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) 
    {
        return atMostK(A, K) - atMostK(A, K-1);
    }
    
    int atMostK(vector<int> & arr, int k)
    {
        int start = 0, end = 0;
        int ans = 0;
        const int n = arr.size();
        
        unordered_map<int, int> mp;
        for(;end < n;end++)
        {
            if(mp[arr[end]]++ == 0)
            {
                k--;
            }
            
            while(k < 0)
            {
                if(--mp[arr[start++]] == 0)
                    k++;
            }
            
            //以end为结尾的合法subarray
            ans += end - start + 1;
        }
        
        return ans;
    }
};

//这个封装成类的想法也很不错
//就粘贴下了
//refer : https://leetcode.com/problems/subarrays-with-k-different-integers/solution/

// class Solution {
//     public int subarraysWithKDistinct(int[] A, int K) {
//         Window window1 = new Window();
//         Window window2 = new Window();
//         int ans = 0, left1 = 0, left2 = 0;

//         for (int right = 0; right < A.length; ++right) {
//             int x = A[right];
//             window1.add(x);
//             window2.add(x);

//             while (window1.different() > K)
//                 window1.remove(A[left1++]);
//             while (window2.different() >= K)
//                 window2.remove(A[left2++]);

//             ans += left2 - left1;
//         }

//         return ans;
//     }
// }

// class Window {
//     Map<Integer, Integer> count;
//     int nonzero;

//     Window() {
//         count = new HashMap();
//         nonzero = 0;
//     }

//     void add(int x) {
//         count.put(x, count.getOrDefault(x, 0) + 1);
//         if (count.get(x) == 1)
//             nonzero++;
//     }

//     void remove(int x) {
//         count.put(x, count.get(x) - 1);
//         if (count.get(x) == 0)
//             nonzero--;
//     }

//     int different() {
//         return nonzero;
//     }
// }