#include <vector>
#include <algorithm>

using namespace std;

//数组/链表归并类型吧
//求出中位数应该所在的次序pos，还要根据数组元素总个数的奇偶来确定需要一个还是两个数
//之后照着归并的想法记录(第pos-1个元素和)第pos个元素
//思路还算简单--
//O(m+n)

//
//O(log(min(m,n)))
//用虚拟加的手法让m+n恒为偶数
//另外引入割的概念
//老实讲并没有参透这个有点巧妙的手法 嘻
//但时间其实差不多--
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
            //如果个数为偶数则要求该位置的数
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
        //有一种情况是一个数组完了mid2还没求好，那么就要在另一个数组里面找啊找
        //和链表归并的想法差不多
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

class _Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m=nums1.size(),n=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int lo=0,hi=2*m+1;
        double l1,r1,l2,r2;
        while(lo<hi){
            int c1=(lo+hi)/2;
            int c2 = m+n-c1;
            l1=c1==0?INT_MIN:nums1[(c1-1)/2];
            r1=c1==2*m?INT_MAX:nums1[c1/2];
            l2=c2==0?INT_MIN:nums2[(c2-1)/2];
            r2=c2==2*n?INT_MAX:nums2[c2/2];

            if(l1>r2){
                hi=c1;
            }else if(l2>r1){
                lo=c1+1;
            }else{
                break;
            }
        }
        return (max(l1,l2)+min(r1,r2))/2;
    }
};