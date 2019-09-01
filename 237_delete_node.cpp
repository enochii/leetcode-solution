/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//move值就完事，不然我拿头去接链表？
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pre=NULL;
        while (node->next)
        {
            node->val=node->next->val;
            pre=node;
            node=node->next;
        }
        pre->next=NULL;
        delete node;
    }
};