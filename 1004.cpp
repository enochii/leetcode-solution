// 1004. Max Consecutive Ones III

#include <vector>

using namespace std;

//Sliding Window
//保证left和right中的所有数字最多经过k次翻转可变成全1

class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int flips=0;
        int left=0,right=0;
        int ans=0;
        int cnt=0;
        while(right<A.size()){
            while(right<A.size()){
                if(A[right]){
                    right++;
                    cnt++;
                    continue;
                }
                if(flips==k)break;
                flips++;//用掉一次机会
                right++;
                cnt++;
            }
            if(right>=A.size())break;
            ans=max(ans,cnt);
            while(left<=right&&A[left]!=0){
                    left++;
                    cnt--;
            }

            left++;
            cnt--;
            //现在left指向了一个1
            //并且回退了一次反转机会
            flips--;              
        }
        return max(ans,cnt);
    }
};