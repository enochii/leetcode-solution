/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 82. Remove Duplicates from Sorted List II

class _Solution {
public:
    //每层递归检查有没有和头部重复的，重复就整个删除
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next )return head;
        
        auto cur = head, next = head->next;
        while(cur && next){
            if(cur->val != next->val)break;
            cur=next;
            next = next->next;
        }
        if(head == cur){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        cur->next = nullptr;
        delete head;
        return deleteDuplicates(next);
    }
};

class Solution {
public:
    //Iteration
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        
        ListNode dummy(-1);
        auto pd = &dummy;
        
        auto start = head;
        auto end = start;
        
        // head = nullptr;
        while(start && end){
            ListNode* prev = nullptr;
            while(end && end->val == start->val){
                prev = end;
                end = end->next;
            }
            
            if(start == prev){
                pd->next = start;
                pd = start;
            }else{
                prev->next = nullptr;
                delete start;
            }
            start = end;
        }
        //记得补上，否则最后一个赋值给pd的节点可能会被delete多次(被多个节点指向)
        pd->next = nullptr;
        
        return dummy.next;
    }
};