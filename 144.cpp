/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//白嫖Medium
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root,res);
        return res;
    }
    void preorder(TreeNode* root, vector<int>& res){
        if(root==NULL)return;
        res.push_back(root->val);
        preorder(root->left,res);
        preorder(root->right,res);
    }
};