/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 445. Add Two Numbers II

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || l1->val == 0)return l2;
        if(!l2 || l2->val == 0)return l1;
        
        // ListNode dummy(1211);
        
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        
        while(l1){
            stk1.push(l1);
            l1=  l1->next;
        }
        while(l2){
            stk2.push(l2);
            l2 = l2->next;
        }
        
        ListNode* tail = nullptr;
        bool carry = 0;
        while(!stk1.empty()||!stk2.empty()){
            int val;
            if(stk2.empty()){
                auto top = stk1.top();stk1.pop();
                val = top->val + carry;
                
            }else if(stk1.empty()){
                stk1.swap(stk2);continue;
            }else{
                auto t1 = stk1.top();stk1.pop();
                auto t2 = stk2.top();stk2.pop();

                val = t1->val + t2->val + carry;
            }
            carry = val >= 10;
            auto head = new ListNode(val - carry * 10);
            head->next = tail;
            tail = head;
        }
        
        if(carry){
            auto head = tail;
            tail = new ListNode(1);
            tail->next = head;
        }
        
        return tail;
    }
};