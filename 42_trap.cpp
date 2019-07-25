#include <vector>
#include <algorithm>

using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

//这东西和剪枝有点像，木桶装水只要求出低的那段就行
//高的那段只要知道它比低的高就行
//8 ms
//9 MB左右
//感觉这个内存有点迷
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2)return 0;

        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;

        int sum = 0;
        while(left < right){
            if(left_max < right_max){
                if(left_max>height[left]){
                    sum += left_max - height[left];
                }else{
                    left_max = height[left];
                }
                left++;
            }else{
                if(right_max>height[right]){
                    sum+=right_max - height[right];
                }else{
                    right_max = height[right];
                }
                right--;
            }
        }
        return sum;
    }
};

//4 ms
//9 MB
//算是一维dp吧...
//计算当前点的左边最大点可以用上一个点的结果，右边最大点同理
class __Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<2){
            return 0;
        }
        const int arr_sz = height.size() - 2;

        
        vector<int> left_max(arr_sz);
        vector<int> right_max(arr_sz);
        // cout<<left_max.size();
        int lmax = height.front();
        int rmax = height.back();
        for(int i=1;i<height.size()-1;i++){
            lmax = left_max[i-1] = max(lmax, height[i]);
            rmax = right_max[arr_sz-i] = max(rmax, height[arr_sz-i+1]);
        }

        int sum = 0;
        for(int i=1;i<height.size()-1;i++){
            // cout<<left_max[i-1]<<" "<<right_max[i-1]<<'\n';
            sum+=min(left_max[i-1], right_max[i-1]) - height[i];
        }
        return sum;
    }
};

//暴力
class _Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int sum = 0;

        for(int i=1;i<height.size()-1;i++){
            int j = i;
            int lmax = height[i], rmax = height[i];
            while(j > 0){
                lmax = max(lmax, height[j-1]);
                j--;
            }
            //
            j = i+1;
            while(j < height.size()){
                rmax = max(rmax, height[j]);
                j++;
            }
            sum+=min(lmax, rmax) - height[i];
        }
        return sum;
    }
};

