/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdlib>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//抄链表归并
//归到最后只剩下一个链表
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        // if(n==1)return lists[0];
        //
        for(int step=1;step<lists.size();step+=step){
            for(int start=0;start+step<lists.size();start+=step*2){
                lists[start]=mergeTwoLists(lists[start],lists[start+step]);
            }
        }
        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* sb = new ListNode(-1);
        ListNode* sb_copy = sb;//return

        while(l1&&l2){
            if(l1->val<=l2->val){
                sb->next = l1;
                l1=l1->next;
            }else{
                sb->next = l2;
                l2=l2->next;
            }
            sb = sb->next;
        }
        if(l1){
            sb->next = l1;
        }else{
            sb->next = l2;
        }
        
        auto ret = sb_copy->next;
        delete sb_copy;
        
        return ret;
    }
};