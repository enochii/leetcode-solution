/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 147. Insertion Sort List
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head)return head;
        ListNode dummy(-1);
        ListNode* sb = & dummy;
        sb->next = head;
        
        auto pre = head;
        for(auto p=head->next; p!=nullptr;pre=p,p=p->next){
            sb = &dummy;
            ListNode* p1;
            //head不(一定)是当时的head
            for(p1 = sb->next;p1!=p;sb = p1,p1=p1->next){
                if(p1->val > p->val)break;
            }
            if(p1 == p)continue;
            
            sb->next = p;
            pre->next = p->next;
            p->next = p1;
            
            
            p=pre;
        }
        return dummy.next;
    }
};