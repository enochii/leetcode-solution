/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstdlib>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//用栈的方法比较直接，维护两个栈
//因为如果存在交集两个链表的尾部完全相同
//只要从后面开始比较即可
class _Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> stackA, stackB;
        
        while(headA!=NULL){
            stackA.push(headA);
            headA=headA->next;
        }

        while(headB!=NULL){
            stackB.push(headB);
            headB = headB->next;
        }

        ListNode* inode = NULL;
        while(!stackA.empty()&&!stackB.empty()
                &&stackA.top()==stackB.top()){
                    inode = stackA.top();
                    stackA.pop();
                    stackB.pop();
        }
        return inode;
    }
};

//相当于把两个链表按不同的顺序首尾相连
//修正两个相交节点的位置差距
class Solution{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p1 = headA, p2 = headB;

        while(p1!=p2){
            p1 = p1?p1->next:headB;
            p2 = p2?p2->next:headA;
        }
        return p1;
    }
};