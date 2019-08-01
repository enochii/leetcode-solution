/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class _Solution {
stack<ListNode*> stk;
public:
    ListNode* reverseList(ListNode* head) {
        while(head){
            stk.push(head);
            head = head->next;
        }
        ListNode* sb = new ListNode(-1);
        ListNode* sb_copy = sb;
        while(!stk.empty()){
            sb->next = stk.top();
            sb=sb->next;
            stk.pop();
        }
        sb->next=NULL;
        auto ret = sb_copy->next;
        delete sb_copy;
        return ret;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //
        typedef ListNode* ptr;
        ptr pre=NULL, cur=head,next,tmp;
        while(cur){
            tmp = cur;
            next = cur->next;
            cur->next = pre;
            pre = tmp;
            cur = next;
        }
        return pre;
    }
};