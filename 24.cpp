// 24. Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    //Iteration
    ListNode* swapPairs(ListNode* head) {
        //题目说明：不要改value，要改ptr...
        
        if(head == nullptr || nullptr == head->next)return head;
        
        //哨兵节点
        ListNode sb(-1);
        
        ListNode* psb = &sb;
        ListNode* prev = head;
        ListNode* next_prev;
        // head = head->next;
        while(prev && prev->next){
            // cout<<prev->val<<' ';
            head = prev->next;
            // cout<<head->val<<'\n';
            
            next_prev = head->next;
            
            // prev->next = next_prev;
            //这个东西记得连上去，否则对于[1,2,3,4]，最后4指向的3，调用方检查的时候会死循环！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
            //另外，单数的话也是需要这个操作的
            //或者直接在循环结束的时候操作psb，效果一样，少做了几次赋值
            
            psb->next = head;
            head->next = prev;
            
            psb = prev;
            prev = next_prev;
        }
        psb->next = next_prev;
        
        // cout<<'!';
        return sb.next;
    }
};

class _Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))return head;
        // if(!(head->next))return head;
        
        auto post = head->next->next;
        
        auto nhead = head->next;
        nhead->next = head;
        head->next = swapPairs(post);
        
        return nhead;
    }
};