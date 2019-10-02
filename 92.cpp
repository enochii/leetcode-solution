// 92. Reverse Linked List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//一开始是想把reverse单独拎出来的，不过这样要传的值很多，包括reverse那部分的首尾指针以及该部分之后的头部
//状态过多大概就说明耦合度比较高吗hhh

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)return head;
        //m == 1
        
        int pos = 1;
        ListNode* beforem = nullptr;
        auto oldhead = head;
        
        while(pos < m){
            pos ++;
            beforem = head;
            head = head->next;
        }
        //现在head指向m的位置,beforem指向m-1（可能为null）
        //执行reverse
        ListNode* prev = nullptr;
        ListNode* aftern;
        auto pm = head;
        
        // cout<<head->val<<'\n';
        
        //因为多了一个空的prev，所以要调整n-m+1次指针.....
        while(pos < n){
            pos++;
            auto tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            aftern = head->next;
            // cout<<aftern->val<<' ';
        }
        // 现在head指向原来的n位置
        //
        // cout<<'\n'<< head->val<<'\n';
        head->next = prev;
        pm->next =aftern;
        if(m==1)return head;
        //else
        beforem->next = head;
        
        return oldhead;
    }
    
};