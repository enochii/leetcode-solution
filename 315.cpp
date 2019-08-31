#include <vector>
#include <algorithm>

using namespace std;

//使用归并排序对下标进行排序
//在合并数组的过程中记录right数组已经过掉的元素，记为cnt
//当某个left进入已排序数组时，意味着它可以加上cnt
//只用加上right数组比left数组元素大的原因时
//left数组内部已经在之前的一次记过了
//为了减少数组的复制，可以用迭代器，两个版本区别挺明显的

class _Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            index[i]=i;
        }
        //
        vector<int> ans(nums.size(),0);
        merge_sort(index,nums,ans);
        return ans;
    }
    //
    vector<int> merge(vector<int>& left, vector<int>& right, vector<int>& nums, vector<int>& ans){
        int l=0, r=0;
        const int ls=left.size(),rs=right.size();

        vector<int> re;
        //每次都在ans数组加上对应位置比nums[left[i]]小的数
        int cnt=0;//已经归并的right数组的元素数目
        while (l<ls && r<rs)
        {
            if(nums[left[l]]>nums[right[r]]){
                cnt++;
                re.push_back(right[r]);
                r++;
            }else{
                //<= stable sort
                ans[left[l]]+=cnt;
                re.push_back(left[l]);
                l++;
            }
        }
        while (l<ls)
        {
            ans[left[l]]+=cnt;
            re.push_back(left[l]);
            l++;
        }
        while (r<rs)
        {
            re.push_back(right[r]);
            r++;
        }
        return re;
    }

    void merge_sort(vector<int>& index, vector<int>& nums,vector<int>& ans){
        if(index.size()<2)return;
        vector<int> left(index.begin(), index.begin()+index.size()/2);
        vector<int> right(index.begin()+index.size()/2, index.end());
        //
        merge_sort(left,nums,ans);
        merge_sort(right,nums,ans);
        //
        index=merge(left,right,nums,ans);
    }

};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            index[i]=i;
        }
        //
        vector<int> ans(nums.size(),0);
        merge_sort(index.begin(),index.end(),nums,ans);
        return ans;
    }
    //
    void merge(vector<int>::iterator beg, vector<int>::iterator mid, vector<int>::iterator end, vector<int>& nums, vector<int>& ans){
        vector<int> tmp(beg,end);
        int midi=mid-beg,endj=end-beg;
        int i=0,j=midi;
        int cnt=0;
        while(i<midi&&j<endj){
            if(nums[tmp[i]]<=nums[tmp[j]]){
                *beg++=tmp[i];
                ans[tmp[i++]]+=cnt;
            }else{
                *beg++=tmp[j++];
                cnt++;
            }
        }
        while (i<midi)
        {
            *beg++=tmp[i];
            ans[tmp[i++]]+=cnt;
        }
        while (j<endj)
        {
            *beg++=tmp[j++];
        }
        
        tmp.clear();
    }

    void merge_sort(vector<int>::iterator beg, vector<int>::iterator end, vector<int>& nums,vector<int>& ans){
        if(end-beg<2)return;
        // vector<int> left(index.begin(), index.begin()+index.size()/2);
        // vector<int> right(index.begin()+index.size()/2, index.end());
        //
        auto mid=beg+(end-beg)/2;
        merge_sort(beg, mid,nums,ans);
        merge_sort(mid, end,nums,ans);
        //
        merge(beg,mid,end,nums,ans);
    }

};