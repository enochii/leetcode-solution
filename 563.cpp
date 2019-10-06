/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 563. Binary Tree Tilt
class Solution {
    int ans = 0;
public:
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
    
    int helper(TreeNode* root){
        if(! root){
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        
        ans+= abs(left - right);
        
        return left+right + root->val;
    }
};