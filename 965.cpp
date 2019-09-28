/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == nullptr)return true;
        return help(root, root->val);
    }
    
    bool help(TreeNode* root, int val){
        if(!root)return true;
        return root->val == val && help(root->left,val) && help(root->right, val);
    }
};