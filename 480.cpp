#include <vector>
// #include <queue>
#include <set>

using namespace std;

// class Solution {
// public:
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         vector<double> ans;
//         if(k>nums.size())return ans;
//         //
//         int l=0,r=k-1;
//         while(r<nums.size()){
//             addone(nums,l,k,ans);
//             l++;r++;
//         }
//         return ans;
//     }

//     void addone(vector<int>& nums, int start, int k, vector<double>& ans){
//         vector<int> tmp(nums.begin()+start,nums.begin()+start+k);
//         int mid=start+k/2;
//         if(k%2==1){
//             ans.push_back(tmp[mid]);
//         }else{
//             ans.push_back(((double)tmp[mid]+tmp[mid+1])/2);
//         }
//     }
// };

//用multiset充当最大最小堆
//主要是可以find，可以重复
//不过要注意下erase的用法
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int,greater<int>> max_heap;//最大堆
        multiset<int> min_heap;//最小堆
        for(int i=0;i<k;i++){
            min_heap.insert(nums[i]);
        }
        //保持min_heap的个数大于(1个)等于max_heap
        //并且min_heap的堆顶大于等于max_heap的堆顶
        //也就是min_heap所有数都大于max_heap的所有数
        for(int i=0;i<k/2;i++){
            // cout<<*min_heap.begin();
            max_heap.insert(*min_heap.begin());
            min_heap.erase(min_heap.begin());
        }
        //
        vector<double> ans;
        for(int i=k;i<nums.size();i++){
            // cout<<'?';
            // cout<<*min_heap.begin()<<' ';
            if(k%2==0){
                // cout<<min_heap.size()<<' '<<max_heap.size()<<'\n';
                ans.push_back(((long long)*min_heap.begin()+*max_heap.begin())/2.0);
            }else{
                ans.push_back(*min_heap.begin());
            }

            //先删除滑过的数字
            if(nums[i-k]<*min_heap.begin()){
                max_heap.erase(max_heap.find(nums[i-k]));
            }else{
                min_heap.erase(min_heap.find(nums[i-k]));
            }
            //接着插入
            //这个判断条件感觉挺关键的，在这里卡了很久
            //
            if(!min_heap.empty() && nums[i]>=*min_heap.begin()){
                min_heap.insert(nums[i]);
            }else{
                max_heap.insert(nums[i]);
            }
            //查看size是否合适
            if(max_heap.size()==k/2)continue;
            if(max_heap.size()<k/2){
                max_heap.insert(*min_heap.begin());
                min_heap.erase(min_heap.begin());
            }else{
                // cout << "move from max to min: "<<*max_heap.cbegin()<<'\n';
                min_heap.insert(*max_heap.begin());
                // cout<<max_heap.size()<<' ';
                max_heap.erase(max_heap.begin());//不能通过r it删除，那就通过值删除
            }
        }
        //
        if(k%2==0){
            ans.push_back(((long long)*min_heap.begin()+*max_heap.begin())/2.0);
        }else{
            ans.push_back(*min_heap.begin());
        }

        return ans;
    }
};