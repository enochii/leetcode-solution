/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 83. Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        //
        auto last = head, cur = head->next;
        
        while(last && cur){
            if(last->val == cur->val){
                last->next = cur->next;
                cur->next = nullptr;
                delete cur;
                cur = last->next;
            }else{
                last = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};

class _Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return nullptr;
        
        helper(head->next, head);
        return head;
    }
    
    void helper(ListNode* cur, ListNode* last){
        if(cur == nullptr)return;
        
        if(
          cur->val != last->val
          ){
            return helper(cur->next, cur);
        }
        
        last->next = cur->next;
        cur->next = nullptr;
        delete cur;
        helper(last->next, last);
    }
};