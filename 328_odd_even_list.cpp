#include <stdlib.h>
// /**
   //Definition for singly-linked list.
   struct ListNode {
       int val;
       ListNode*  next;
       ListNode(int x) : val(x), next(NULL) {}
   };
//  */
//我们可以分别把单数和双数串起来
//然后再首尾相接
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        ListNode n1(-1),n2(-1);
        auto p1=&n1,p2=&n2;

        //
        while(head){
            //循环跳出时可以保证p1不为NULL
            p1->next=head;
            p1=p1->next;
            head=head->next;
            //
            p2->next=head;
            p2=p2->next;
            if(!head)break;
            head=head->next;
        }
        p1->next=n2.next;
        return n1.next;
    }
};