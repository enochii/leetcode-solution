#include <vector>
#include <algorithm>

using namespace std;

//是不是可以用一个单调递增栈来做
//不可以！单调栈一般是那种连续情况！

//观察可以发现，能做左边界的必定在其左边不会有比它高或者相等的
//右边界同理
//所以一种比较简单的方法就是把左右所有可能的候选值拿出来
//枚举就ok

//可以用双指针...我好菜啊
class _Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)return 0;
        //
        vector<int> left_candidates,right_candidates;
        int lmax=-1;
        for(int i=0;i<height.size();i++){
            if(lmax<height[i]){
                left_candidates.push_back(i);
                lmax=height[i];
            }
        }
        int rmax=-1;
        for(int i=height.size()-1;i>=0;i--){
            if(rmax<height[i]){
                right_candidates.push_back(i);
                rmax=height[i];
            }
        }
        //
        int ans=0;
        for(auto l:left_candidates){
            for(auto r:right_candidates){
                if(l>=r)break;
                ans=max(ans,(r-l)*min(height[l],height[r]));
                //优化，但其实用处不大--
                if(height[l]<=height[r]){
                    break;
                }else{
                    //可以把这个erase掉的，但是vector的erase不太好的样子
                    // right_candidates.erase()
                }
            }
        }
        return ans;
    }
};

//双指针，减少一些没必要的计算
//感觉和前面思路有点像
//维护一个lmax和rmax
//小的需要继续前进，因为它已经完成了它的使命 -> 
//不会找到更长的底了！

//有点眼熟，和那道计算储存水有点类似
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()<2)return 0;
        int l=0, r=height.size()-1;
        int lmax=height[l], rmax=height[r];

        int ans=0;
        while(l<r){
            int h=0, w=r-l;
            if(lmax>rmax){
                h=rmax;
                r--;
                rmax=height[r];
            }else if(lmax<rmax){
                h=lmax;
                l++;
                lmax=height[l];
            }else{
                r--;l++;
                h=lmax;
                lmax=height[l];
                rmax=height[r];
            }
            ans=max(ans,h*w);
        }
        return ans;
    }
};