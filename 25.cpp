// 25. Reverse Nodes in k-Group

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//栈
//确认长度后再进行reverse
class _Solution {
    stack<ListNode*> stk;
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return nullptr;
        
        auto oldhead = head;
        for(int i=0;i<k - 1;i++){
            stk.push(head);
            head = head->next;
            if(head == nullptr)return oldhead;
        }
        if(!head)return oldhead;
        //
        auto next = head->next;
        auto ret = head;
        
        while(!stk.empty()){
            head->next = stk.top();
            stk.pop();
            head = head->next;
        }
        //
        head->next = reverseKGroup(next, k);
        
        return ret;
    }
};

//先reverse，长度不够再reverse一次
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)return nullptr;
        
        ListNode* oldhead = head;
        ListNode* prev = nullptr;
        int i;
        for(i=0;i<k && head ;i++){
            auto tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        //
        if(i < k){
            auto ppre = prev;
            prev = nullptr;
            for(int j=0;j<i;j++){
                auto next = ppre->next;
                ppre->next = prev;
                prev = ppre;
                ppre = next;
            }
            return prev;
        }
        
        oldhead->next = reverseKGroup(head, k);
        return prev;
    }
};