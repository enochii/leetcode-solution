#include <vector>

using namespace std;

class Solution {
public:
    //我感觉可以从后面进行归并排序
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1.swap(nums2);
            return;
        }
        if(n==0){
            return;
        }
        int pos=m+n-1;
        int p1=m-1,p2=n-1;
        while(p1>=0&&p2>=0){
            if(nums1[p1]<=nums2[p2]){
                nums1[pos--]=nums2[p2--];
            }else{
                nums1[pos--]=nums1[p1--];
            }
        }
        while(p1>=0){
            nums1[pos--]=nums1[p1--];
        }
        while(p2>=0){
            nums1[pos--]=nums2[p2--];
        }
    }
};