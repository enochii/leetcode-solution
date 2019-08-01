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

class _Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        if(n==0)return head;

        auto head_copy = head;
        while(head){
            vec.push_back(head);
            head=head->next;
        }
        const int sz=vec.size();
        if(n==sz){
            delete(vec[0]);
            return sz>1?vec[1]:NULL;
        }
        //
        vec[sz-n-1]->next=vec[sz-n]->next;
        delete(vec[sz-n]);

        return vec[0];
    }
};

//常量空间+一遍pass
//有点东西
//sz-n还行，判断步数后从头开始...牛逼
//虽然是一遍pass，但事实上遍历了不止一遍链表...哦日
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nth = NULL, *nth_pre = NULL, *cur = head;
        if(!head)return head;
        int step = 0;
        while(cur){            
            step++;
            cur=cur->next;
            //sz-n次
            if(nth){
                nth=nth->next;
            }
            if(nth_pre){
                nth_pre=nth_pre->next;
            }
            //
            if(n==step){
                nth = head;
            }else if(n==step-1){
                nth_pre = head;
            }
        }
        
        if(nth_pre){
            nth_pre->next = nth->next;
            return head;
        }else{
            auto ret = nth->next;
            delete nth;
            return ret;
        }
    }
};