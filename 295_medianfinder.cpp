#include <deque>

using namespace std;

//也有维护一个最大堆和最小堆的解法，时间快了不少捏

//二分插入，维护一个数组
class MedianFinder {
deque<int> dq;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int lo=0, hi=dq.size();
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(dq[mid]>=num){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        //原来empty也是可以insert到begin的，好
        dq.insert(dq.begin()+lo, num);
    }
    
    double findMedian() {
        const int sz = dq.size();
        int mid = sz/2;
        return sz%2?dq[mid]:(dq[mid]+dq[mid-1])/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */