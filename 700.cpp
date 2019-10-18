
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 700. Search in a Binary Search Tree
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)return root;
        
        if(root->val == val)return root;
        return root->val > val ? searchBST(root->left,val):searchBST(root->right, val);
    }
};