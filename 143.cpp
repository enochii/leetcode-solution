/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 143. Reorder List

//另一种方法：还可以用双指针去track它的走向
//一串串两个

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> v;
        while(head){
            v.push_back(head);
            head=head->next;
        }
        
        ListNode dummy(-1);
        auto pd = &dummy;
        
        const int sz = v.size();
        for(int i=0;i<sz;i++){
            int index = (i&1) == 0?i/2:(sz-1-i/2);
            cout<<index<<' ';
            pd->next = v[index];
            pd = pd->next;
        }
        pd->next = nullptr;
        
        // return dummy.next;
    }
};

