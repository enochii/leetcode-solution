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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    //采用中序遍历的逆？
public:
    TreeNode* convertBST(TreeNode* root) {
        int val=0;
        inorder(root, val);
        return root;
    }

    void inorder(TreeNode* root, int& val){
        if(!root)return;
        //
        inorder(root->right, val);
        root->val+=val;
        inorder(root->left, val=root->val);
    }
};