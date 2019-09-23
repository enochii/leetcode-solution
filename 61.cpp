/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//这种还可以先固让一个指针p往后走k步
//现在p离链表尾部还有len-k步
//然后让p和一个从头开始的q同时往后走
//等p到达尾部，那么q就会指向那个分割点
//接下来就是改变指针指向即可
//相对第二种解法在k<len时会有点优势，只走了一遍循环
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        auto p=head;
        int size=0;
        while(k>0){
            k--;
            if(p){
                p=p->next;
                size++;
            }else{
                // cout<<size<<'\n';
                k%=size;//先取余嗷
                size++;
                p=head->next;//弥补一次空转的k--
            }
        }
        //这里的p==head也可以不判断的...
        //也就是k==len * N的情况下
        //不过下面在改变指针指向就有点技巧
        //就是注意链接的顺序，先形成环再拆开
        if(p==NULL||p==head)return head;
        // cout<<p->val;
        auto q=head;
        while(p->next){
            p=p->next;
            q=q->next;
        }
        p->next=head;
        auto ret=q->next;
        q->next=NULL;
        
        
        return ret;
    }
};

class Solution_ {
public:
    //粗暴点的做法是扫描两次
    //先扫一遍获取len
    //然后前进(len-k)步
    //把链再接起来
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return head;
        int len=0;
        auto tmp=head;
        while(tmp){
            tmp=tmp->next;
            len++;
        }
        //
        k=k%len;
        if(k==0)return head;
        auto sp=head;//split_pos
        for(int i=1;i<len-k;i++){
            sp=sp->next;
        }
        //
        auto nhead=sp->next;
        sp->next=NULL;
        tmp=nhead;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=head;
        return nhead;
    }
};