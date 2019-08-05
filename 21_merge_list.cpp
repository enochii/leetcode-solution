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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* sb = new ListNode(-1);
        ListNode* sb_copy = sb;//return

        while(l1&&l2){
            if(l1->val<=l2->val){
                sb->next = l1;
                l1=l1->next;
            }else{
                sb->next = l2;
                l2=l2->next;
            }
            sb = sb->next;
        }
        if(l1){
            sb->next = l1;
        }else{
            sb->next = l2;
        }
        
        auto ret = sb_copy->next;
        delete sb_copy;
        
        return ret;
    }
};