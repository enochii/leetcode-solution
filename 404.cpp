// 404. Sum of Left Leaves


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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr)return 0;
        int ans = 0;
        if(root->left)ans+=sum(root->left,root);
        if(root->right)ans+=sum(root->right, root);
        
        return ans;
    }
    
    int sum(TreeNode* root, TreeNode* par){
        if(root->left == nullptr){
            if(root->right == nullptr)return root == par->left?root->val:0;//叶节点
            return sum(root->right, root);
        }
        
        if(root->right == nullptr){
            return sum(root->left, root);
        }
        
        return sum(root->left, root) + sum(root->right, root);
    }
};