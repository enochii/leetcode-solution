#include <vector>
#include <deque>

using namespace std;

// class NestedInteger {
// public:
//     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//     bool isInteger() const;

//     // Return the single integer that this NestedInteger holds, if it holds a single integer
//     // The result is undefined if this NestedInteger holds a nested list
//     int getInteger() const;
//     // Return the nested list that this NestedInteger holds, if it holds a nested list
//     // The result is undefined if this NestedInteger holds a single integer
//     const vector<NestedInteger> &getList() const;
// };

//想法是维护一个NestedInt双端队列
//然后在需要的时候在前部取值就行
//有一个问题是可能是[[]]的case
//导致你的hasNext()是错的
//当然我们可以加入一个notempty()，虽然过了效率奇低
//原因是你需要两次展开这样的结构，一次是检测到notempty，一次是真实的取值，比如下面：
//[[[[[[[[[[[[[]]]]]]]]]]]]]
//所以你不如在检测的时候就try to push
//最终导致你在构造一个NestedIterator的时候，直接可以整出来一个deque<int>而不是deque<NestedInterger>
//而且NestedInt还要考虑拷贝的问题
//这两种事实上就是eager和lazy的区别了
//而且eager的话用queue就够了...

//好像也可以无脑push，在hasNest()做手脚
class NestedIterator {

    deque<int> dq;
    //try to push
    void try_push(const NestedInteger& ni){
        if(ni.isInteger()){
            dq.push_back(ni.getInteger());
            // return;
        }
        auto & vec=ni.getList();
        // if(vec.empty())return false;
        for(int i=0;i<vec.size();i++){
            try_push(vec[i]);
        }
        // return false;
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0;i<nestedList.size();i++){
            try_push(nestedList[i]);
        }
    }

    int next() {
        auto top=dq.front();
        dq.pop_front();
        return top;
    }

    bool hasNext() {
        return !dq.empty();
    }
};

// /
//   Your NestedIterator object will be instantiated and called as such:
//   NestedIterator i(nestedList);
//   while (i.hasNext()) cout << i.next();
//  


// class _NestedIterator {

//     deque<NestedInteger> dq;
//     bool notempty(const NestedInteger& ni){
//         if(ni.isInteger())return true;
//         auto & vec=ni.getList();
//         // if(vec.empty())return false;
//         for(int i=0;i<vec.size();i++){
//             if(notempty(vec[i]))return true;
//         }
//         return false;
//     }
// public:
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         for(auto ni:nestedList){
//             if(notempty(ni))dq.push_back(ni);
//         }
//     }

//     int next() {
//         auto top=dq.front();
//         dq.pop_front();
//         if(top.isInteger()){
//             return top.getInteger();
//         }
//         //
//         auto vec=top.getList();
//         for(auto i=vec.size();i>0;i--){
//             if(notempty(vec[i-1]))dq.push_front(vec[i-1]);
//         }
//         //因为这nm是个递归的结构，所以...
//         //要递归到deque的front是一个int
//         return next();
//     }

//     bool hasNext() {
//         return !dq.empty();
//     }
// };
