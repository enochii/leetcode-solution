#include <vector>

using namespace std;

//归并排序
//mergesort

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty())return 0;
        //看了好久才明白题目的意思
        //就是找出range sum在[lower,upper]区间内的个数

        //先做一个数组
        vector<long long> sums(nums.size(),0);//这里有个0
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sums[i]=sum;
        }
        //这样问题转化成两数之差在[lower, upper]范围内的组合数
        return merge(sums,0,sums.size(),lower, upper);
    }
    
    int merge(vector<long long> &sum, int left, int right, int lower, int upper){
        if(left>=right)return 0;//empty
        if(left==right-1)return lower<=sum[left]&&sum[left]<=upper;//single
        //左右子数组各自的cnt
        int mid=left+(right-left)/2;
        int cnt=merge(sum,left,mid,lower,upper)+merge(sum,mid,right,lower,upper);
        // cout<<cnt<<' ';
        //这样的复杂度跟穷举没啥区别吧...
        //我感觉应该是可以加个二分搜的--，这样搞没有充分利用有序这个条件
        //加了个二分时间其实差不多...
        //老实说感觉不加二分复杂度挺高的，不过看起来数组好像都挺小的
        //设n=right-left，那么下面(没有二分)最坏循环复杂度为O(n*n)...

        //tmd，命名好难，m写成mid debug到头秃
        for(int i=left,j=mid,k=mid;i<mid;i++){
            // while(j<right&&sum[j]-sum[i]<lower)j++;
            int r=right;
            while(j<r){
                // cout<<j<<' '<<r<<'\n';
                int m=(j+r)/2;
                if(sum[m]-sum[i]<lower)j=m+1;
                else r=m;
            }
            
            r=right;
            // while(k<right&&sum[k]-sum[i]<=upper)k++;
            while(k<r){
                // cout<<k<<' '<<r<<'\n';
                int m=(k+r)/2;
                if(sum[m]-sum[i]<=upper)k=m+1;
                else r=m;
            }
            // cout<<k<<' '<<j<<' ';
            cnt+=k-j;
        }
        //归并，其实我觉得这里不排序好像也行吧...
        vector<long long> tmp(right-left);
        int pos=0;
        for(int i=left,j=mid;(i<mid||j<right)&&pos<tmp.size();){
            if(i>=mid){
                tmp[pos++]=sum[j++];
            }else if(j>=right){
                tmp[pos++]=sum[i++];
            }else if(sum[i]<=sum[j]){
                tmp[pos++]=sum[i++];
            }else{
                tmp[pos++]=sum[j++];
            }
        }
        //写入原数组，完成归并
        for(int i=left;i<right;i++){
            sum[i]=tmp[i-left];
        }
        return cnt;
    }
};

//暴力不能过
//事实上还是纠结那个没二分的版本
//复杂度肯定是O(n*n)的，感觉只是多了一些类似剪枝之类的
class _Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty())return 0;
        
        vector<long long> sums(nums.size(),0);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            sums[i]=sum;
        }
        //
        int cnt=0;
        for(int i=0;i<sums.size();i++)if(sums[i]<=upper&&sums[i]>=lower)cnt++;
        for(int i=0;i<sums.size();i++){
            for(int j=i+1;j<sums.size();j++){
                int sub=sums[j]-sums[i];
                if(sub<=upper&&sub>=lower)cnt++;
            }
        }
        return cnt;
    }
};