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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = ListNode(-1);
        auto pd = & dummy;
        
        while(head){
            if(head->val == val){
                auto tmp = head;
                head = head->next;
                tmp->next = nullptr;
                delete tmp;
            }else{
                pd->next = head;
                head = head->next;
                pd = pd->next;
            }
        }
        pd->next = nullptr;
        
        return dummy.next;
    }
};

//看到个有点意思的solution

class Solution {
public:
ListNode *removeElements(ListNode *head, int val)
{
    //直接改变指针
    ListNode **list = &head;

    while (*list != nullptr)
    {
        if ((*list)->val == val)
        {
            *list = (*list)->next;
        }
        else
        {
            list = &(*list)->next;
        }
    }

    return head;
}
};