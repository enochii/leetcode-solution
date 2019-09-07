// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //中序和后序遍历
        return build(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }

    typedef vector<int>::iterator it;
    TreeNode* build(it ibeg, it iend, it pbeg, it pend){
        if(pend==pbeg)return NULL;
        int root_val=*(pend-1);

        auto root=ibeg;
        while(*root!=root_val){
            root++;
        }
        int lcnt=root-ibeg;//左子树的节点数
        // int rcnt=iend-root;//右子树的节点数
        auto l=build(ibeg,root,pbeg,pbeg+lcnt);
        auto r=build(root+1,iend,pbeg+lcnt,pend-1);

        TreeNode* ret=new TreeNode(root_val);
        ret->left=l;
        ret->right=r;

        return ret;
    }
};