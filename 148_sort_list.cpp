/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* sortList(ListNode* head){
        //递归出口
        if(!head || !(head->next)){
            return head;
        }

        //快慢指针
        ListNode *slow = head, *fast = head;
        //哈哈这里其实两个节点没有正确处理
        //不过下面的调整做了修正
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        auto nhead = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(nhead));
        
//         ListNode* prev_slow = NULL;
//         while(fast&&fast->next){
//             prev_slow = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

        
//         prev_slow->next = NULL;
//         // cout<<head->val;

//         return merge(sortList(head), sortList(slow));
    }

    //把哨兵节点拉出来，加速...
    //56ms -> 44ms
    //28.6 MB -> 11.8 MB
    ListNode sbn = ListNode(-1);
    ListNode * const sb_copy = &sbn;

    ListNode* merge(ListNode* h1, ListNode* h2){
        if(!h1)return h2;
        if(!h2)return h1;

        //
        ListNode* sb = sb_copy;
        // ListNode* sb_copy = sb;

        while(h1&&h2){
            if(h1->val>h2->val){
                sb->next = h2;
                sb=sb->next;
                h2 = h2->next;
            }else{
                sb->next = h1;
                sb=sb->next;
                h1=h1->next;
            }
        }
        sb->next = h1?h1:h2;
        auto ret = sb_copy->next;
        // delete sb_copy;

        return ret;
    }
};

//其实我不知道为啥会TLE rnxm
class _Solution {
public:
    ListNode* sortList(ListNode* head) {
        //算出链表长度
        int len = 0;
        for(auto _h = head;_h!=NULL;_h=_h->next,len++);

        for(int i=1;i<len;i<<=1){
            head = sort(head, i);
        }
        return head;
    }
        //假设h的所有长度为size的子链表已经分别有序
        //对其进行合并
        //当链表元素小于等于size*2时，返回true标志已经结束
        ListNode* sort(ListNode* head, int size){
            bool first = true;
            ListNode* ret = NULL;

            ListNode* sb_copy = new ListNode(-1);
            while(head != NULL){
                auto sec_head = head;
                for(int i = 0;i<size&&sec_head!=NULL;i++){
                    sec_head = sec_head->next;
                }
                //剩下的元素数量不足，不需要排序
                if(!sec_head){return ret;}

                //两个指针各自的偏移量
                int i = 0, j = 0;
                //哨兵节点
                // ListNode* sb = new ListNode(-1);
                ListNode* sb = sb_copy;
                sb->next = NULL;

                while(i<size&&j<size&&sec_head!=NULL){
                    if(head->val<sec_head->val){
                        sb->next = head;
                        sb = sb->next;
                        //
                        head = head->next;
                        i++;
                    }else{
                        sb->next = sec_head;
                        sb=sb->next;
                        sec_head = sec_head->next;
                        j++;
                    }
                    
                }
                //检查还没完全合并的链表
                if(i<size){
                    sb->next = head;
                    while(i<size-1){
                        head = head->next;
                    }
                    head->next=sec_head;
                }else{
                    sb->next = sec_head;
                    while(j<size&&sec_head){
                        sec_head = sec_head->next;
                    }
                }
                //继续推进
                head = sec_head;

                if(first){
                    ret = sb_copy->next;
                    first = false;
                }
                // delete sb_copy;
            }
            delete sb_copy;

            return ret;
        }
};

//错误答案不过testcase被报TLE，stmd


// int main(){
//     typedef ListNode* ptr;
    
//     ptr n1 = new ListNode(4),n2 = new ListNode(2),
//                 n3 = new ListNode(1), n4 = new ListNode(3);
//     n1->next = n2;n2->next = n3;n3->next = n4;n4->next = NULL;
//     Solution().sortList(n1);

//     return 0;
// }