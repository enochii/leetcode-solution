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
    ListNode* partition(ListNode* head, int x) {
        //感觉和unique有点像
        //不过这里是一个stable的交换
        //所以开了一个数组记录一下
        auto p=head,q=head;
        vector<int> gar;
        while(p){
            if(p->val<x){
                if(p!=q){
                    swap(p->val,q->val);
                }
                q=q->next;
            }else{
                gar.push_back(p->val);
            }
            
            p=p->next;
        }
        for(int num:gar){
            q->val=num;
            q=q->next;
        }
        
        return head;
    }
};