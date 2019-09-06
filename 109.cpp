#include <stdlib.h>
#include <vector>

using namespace std;

// /**
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//  */
// /**
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//  */
class _Solution {

    typedef vector<ListNode*>::iterator it;
    TreeNode* build(it beg, it end){
        if(end-beg==0)return NULL;
        auto mid=beg+(end-beg)/2;
        auto l=build(beg,mid);
        auto r=build(mid+1,end);

        auto node=new TreeNode((*mid)->val);
        node->left=l;
        node->right=r;

        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //用数组比较舒服？
        vector<ListNode*> nodes;
        while(head){
            nodes.push_back(head);
            head=head->next;
        }

        return build(nodes.begin(),nodes.end());
    }
};

//
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt=0;
        // auto left=head,right=head;
        auto h=head;
        while(h){
            h=h->next;
            cnt++;
        }
        return build(head,cnt);
    }

    //从h开始有cnt个节点
    TreeNode* build(ListNode* h, int cnt){
        if(cnt==0)return NULL;
        auto mid=h;
        int lc=cnt/2;
        for(int i=0;i<lc;i++){
            mid=mid->next;
        }
        //现在[h, mid]有lc个节点
        auto root=new TreeNode(mid->val);
        int rc=cnt-lc-1;
        auto l=build(h,lc);
        auto r=build(mid->next,rc);
        root->left=l;
        root->right=r;

        return root;
    }
};
