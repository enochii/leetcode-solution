#include <vector>

using namespace std;

//抄一手树状数组送给自己
//https://blog.csdn.net/dreamgchuan/article/details/51173561 代码
//https://blog.csdn.net/flushhip/article/details/79165701 原理
class NumArray {
    vector<int> tarr;
    vector<int> nums;
public:
    NumArray(vector<int>& _nums):tarr(_nums.size()+1),nums(_nums) {
        tarr[0]=0;
        for(int i=1;i<tarr.size();i++){
            _update(i,nums[i-1]);
        }
    }
    
    
    void update(int i, int val) {
        _update(i+1,val-nums[i]);
        nums[i]=val;
    }
    
    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
private:
    int lowbit(int x){
        return x&(-x);
    }
    //这里的val是指更新的delta值
    void _update(int i, int val) {
        for(;i<tarr.size();i+=lowbit(i)){
            tarr[i]+=val;
        }
    }

    int sum(int i){
        int ret=0;
        for(;i>0;i-=lowbit(i)){
            ret+=tarr[i];
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */