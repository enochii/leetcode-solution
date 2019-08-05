#include <vector>
#include <algorithm>

using namespace std;

class _MinStack {
    vector<int> dq;
public:
    /** initialize your data structure here. */
    _MinStack() {
        /*empty */
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    void pop() {
        dq.pop_back();
    }
    
    int top() {
        return dq.back();
    }
    
    int getMin() {
        int Min = INT_MIN;
        for(auto i:dq){
            Min = min(Min, i);
        }
        return Min;
    }
};

//记录一个min_val
//当发生min_val更新时把次最小压入栈中
//当把min_val pop出去就在取栈顶再pop，获得次最小值
class MinStack {
    vector<int> dq;
    int min_val = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        /*empty */
    }
    
    void push(int x) {
        if(dq.empty()||min_val>=x){
            dq.push_back(min_val);
            min_val = x;
        }
        dq.push_back(x);
    }
    
    void pop() {
        int t = dq.back();
        dq.pop_back();
        if(min_val == t){
            min_val = dq.back();
            dq.pop_back();
        }
    }
    
    int top() {
        return dq.back();
    }
    
    int getMin() {
        return min_val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */