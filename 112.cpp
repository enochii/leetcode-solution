/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Path Sum, tree

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        if(sum==0&&!root->left&&!root->right)return true;
        return hasPathSum(root->left,sum-root->val) ||
            hasPathSum(root->right,sum-root->val);
    }
};