// 493. Reverse Pairs
// Merge Sort

//给力嗷
//一开始看到i<j有想过mergesort，不过一下子就打消念头是什么鬼
//其实一个重点是如何计算两边之间符合要求的cnt
//需要充分利用之前的计算结果才不会超时
//也就是对于i1<i2，(i1,j)符合要求那么必定(i2,j)也符合要求

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums.begin(),nums.end());
    }
    
    typedef vector<int>::iterator It;
    int mergesort(It first, It last){
        if(last-first<2)return 0;
        //
        auto mid= first+(last-first)/2;
        int ans=mergesort(first,mid);
        ans+=mergesort(mid,last);
        //
        auto first2=mid;
        for(auto it=first;it!=mid;it++){
            while(first2<last&&*first2 * 2ll<*it)first2++;
            ans+=first2-mid;
        }
        
        vector<int> vec(last-first);
        merge(first,mid,last,vec);
        
        int i=0;
        for(It it=first;it!=last;it++){
            *it=vec[i++];
        }
        
        return ans;
    }
    
    void merge(It first, It mid, It last, vector<int>& vec){
        // int ans=0;
        int index=0;
        auto first2=mid;
        while(first<mid&&first2<last){
            if(*first<*first2){
                vec[index++]=*first++;
            }else{
                vec[index++]=*first2++;
                // int tmp = vec[index++]=*first2++;
                // auto it=first;
                // for(;it!=mid&&*it<=2ll*tmp;it++);
                // ans+=mid-it;
            }
        }
        
        while(first<mid){
            vec[index++]=*first++;
        }
        
        while(first2<last){
            vec[index++]=*first2++;
        }
        
        // return ans;
    }
};