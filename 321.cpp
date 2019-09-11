#include <vector>
#include <algorithm>

using namespace std;

//有点烦啊
//比较有收获的是那个generateVec函数(Vec,k)：产生稳定序的k位最大数
//学了个resize

//坑的是合并两个数组变成一个最大数
//当两个数组的相同元素遭遇，你pick哪个的问题
//这明显得向后看
//其实这就是一个string比较也就是vector自带的比较
//不过一开始没想通，再加上一般是后半个数组，所以得自己写一下

//当遇到这种情况
//我们向后找到两个不同的数，直接比较
//如果i==nums1.size()，证明nums1[i:]是nums2[j:]的前缀
//我们肯定可以优先选择nums2的相同元素排在前
//因为这让我们有更多选择

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        const int m=nums1.size(),n=nums2.size();
        vector<int> res;
        for(int n1=max(0,k-n);n1<=min(k,m);n1++){
            res=max(res, mergeVec(generateVec(nums1,n1) ,generateVec(nums2,k-n1)));
        }
        return res;
    }

    vector<int> mergeVec(vector<int> nums1, vector<int> nums2){
        // auto res1=generateVec(nums1,n1);
        // auto res2=generateVec(nums2,n2);

        //归并排序
        vector<int>ans;
        int p1=0,p2=0;
        while(p1<nums1.size()||p2<nums2.size()){
            if(p1>=nums1.size()){
                ans.push_back(nums2[p2++]);
                // continue;
            }else if(p2>=nums2.size()){
                ans.push_back(nums1[p1++]);
            }else{
                if(nums1[p1]>nums2[p2]){
                    ans.push_back(nums1[p1++]);
                }else if(nums1[p1]<nums2[p2]){
                    ans.push_back(nums2[p2++]);
                }else if(compare_after(nums1,nums2,p1,p2)){
                    //相等需要往后走....
                    ans.push_back(nums2[p2++]);
                }else{
                    ans.push_back(nums1[p1++]);
                }
            }

        }
        return ans;
    }

    //判断谁大
    //1 < 2 true
    bool compare_after(vector<int>& nums1,vector<int>& nums2,int i, int j){
        while(i<nums1.size()&&j<nums2.size()&&nums1[i]==nums2[j]){
            i++;
            j++;
        }
        //
        // cout<<nums1[i]<<' '<<nums2[j];
        if(i==nums1.size()){
            //i是j的前缀
            return j!=nums2.size();
        }
        if(j==nums2.size())return false;
        return nums1[i]<nums2[j];
    }

    //在nums
    vector<int> generateVec(vector<int>& nums, int cnt){
        vector<int> res;
        int drop=nums.size()-cnt;
        if(drop==0)return nums;
        for(int num:nums){
            while(drop>0&&!res.empty()&&res.back()<num){
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(cnt);//比较关键
        return res;
    }
};