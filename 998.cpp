/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 998. Maximum Binary Tree II
// 就是说这个节点在原来的最后喽

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(!root)return new TreeNode(val);
        
        if(root->val < val){
            auto nroot = new TreeNode(val);
            nroot->left = root;
            return nroot;
        }
        
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};