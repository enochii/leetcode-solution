/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//每次返回最底部的节点，然后可以链上去...
//一个点是节点的delete是由那边做的，所以记得把left置为NULL...否则会出现重复delete

class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
    
    TreeNode* helper(TreeNode* rt){
        if(!rt)return NULL;
        auto l=helper(rt->left);
        auto r=helper(rt->right);

        auto ret = rt;
        auto rc=rt->right;
        if(l){
            ret->right=ret->left;
            ret=l;
        }
        if(r){
            ret->right=rc;
            ret=r;
        }
        rt->left=NULL;
        return ret;
    }
};

// int main(){
//     typedef TreeNode* ptr;
//     ptr n1=new TreeNode(1);
//     ptr n2=n1->left=new TreeNode(2);
//     ptr n3=n1->right=new TreeNode(5);
//     n2->left=new TreeNode(3),n2->right=new TreeNode(4);
//     n3->right=new TreeNode(6);

//     Solution().flatten(n1);

//     while(n1){
//         cout<<n1->val<<' ';
//         n1=n1->right;
//     }
// }