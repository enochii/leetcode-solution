/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//可以借助一个栈反向遍历sz/2个元素,和正向的作比较...不过空间不是O(1)

//先找到中间元素
//把链表拆成两个，并把后面的reverse，判断值是否相等
class Solution {
public:
typedef ListNode* ptr;
    bool isPalindrome(ListNode* head) {
        ptr slow=head, fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        if(fast){
            //单数
            slow = slow->next;
        }
        auto after = reverse(slow);

        ptr p1=head, p2=after;
        while(p2){
            if(p2->val!=p1->val)return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }

    ptr reverse(ptr head){
        ptr prev=NULL, cur=head, next;
        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};