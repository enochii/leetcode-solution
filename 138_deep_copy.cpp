/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
//random指针是不需要复制的，但是需要赋值到新生的指针上面
//但是你在deepcopy的过程中random可能指向远在当前节点之后的节点
//这时候可以扫两遍，在第一遍把老指针到新指针的映射存下来
//其余的步骤其实跟平凡的深复制一样
//第二遍再把random补上就行
//但是如果我们只想一遍就能把random也给填上，那么可能在某些节点需要跳跃到random指针进行复制
class _Solution {
    typedef Node* nptr;
public:
    Node* copyRandomList(Node* head) {
        unordered_map<nptr,nptr> mp;
        return deepcopy(head,mp);
    }

    //链向后面的random节点可能需要提前复制
    nptr deepcopy(nptr head, unordered_map<nptr,nptr> &mp){
        if(head==NULL){
            return NULL;
        }
        //
        nptr nhead=NULL;
        if(mp.find(head)==mp.end()){
            nhead=mp[head]=new Node(head->val,NULL,NULL);
        }else{
            return mp[head];
        }
        if(mp.find(head->random)==mp.end()){
            nhead->random=mp[head->random]=deepcopy(head->random,mp);
        }else{
            nhead->random=mp[head->random];
        }
        //
        nhead->next=deepcopy(head->next,mp);
        return nhead;
    }
};

//看到了一种有点牛逼的想法
//首先平凡复制
//在复制的过程中把老节点和新节点交叉链接起来
//这样做的目的是老节点的next事实上就是新节点
//我们就可以省去一个map的内存了！

//不过看起来好像是空间换时间
//unordered_map还是很牛逼的
class Solution {
    typedef Node* nptr;
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        nptr p=head,q=NULL;
        while(p){
            q=new Node(p->val,p->next,p->random);
            p->next=q;
            p=q->next;
        }
        //
        p=head->next;
        while(p){
            if(p->random){
                p->random=p->random->next;
            }
            if(p->next==NULL){
                break;
            }else{
                p=p->next->next;//跳过老节点
            }
        }
        //

        p=head, q=head->next;
        nptr ans=q;
        while(p){
            p->next=q->next;
            if(q->next){
                q->next=q->next->next;
            }else{
                break;
            }
            p=p->next;
            q=q->next;
        }
        return ans;
    }
};