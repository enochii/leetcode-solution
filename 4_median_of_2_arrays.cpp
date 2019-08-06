#include <vector>

using namespace std;

//数组/链表归并类型吧
//求出中位数应该所在的次序pos，还要根据数组元素总个数的奇偶来确定需要一个还是两个数
//之后照着归并的想法记录(第pos-1个元素和)第pos个元素
//思路还算简单--
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m=nums1.size();
        const int n=nums2.size();
        int mid = (m+n)/2+1;//
        bool doub=!((m+n)%2);
        int step=0;

        int pos1=0,pos2=0;
        double mid1=0.0,mid2=0.0;
        // bool mid1_assigned = false;
        while(pos1<m&&pos2<n){
            int les;
            if(nums1[pos1]<nums2[pos2]){
                les=nums1[pos1];
                pos1++;
            }else{
                les=nums2[pos2];
                pos2++;
            }
            step++;
            if(doub&&step==mid-1){
                mid1=les;
                // mid1_assigned = true;
            }
            if(step==mid){
                mid2=les;
                break;
            }
        }

        // cout<<step<<' '<<mid<<' '<<pos2<<'\n';
        if(step<mid){
            auto& nums = pos1<m?nums1:nums2;
            auto pos = pos1<m?pos1:pos2;

            //num[pos]还没被选过
            if(doub&&step<mid-1){
                mid1=nums[pos+mid-1-step-1];
            }
            mid2=nums[pos+mid-1-step];
        }
        return doub?(mid1+mid2)/2:mid2;
    }
};