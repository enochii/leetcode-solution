/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//687. Longest Univalue Path
class Solution {
    int ans;
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        
        recur(root);
        return ans;
    }
    
    //从root延展出去的最大长度
    int recur(TreeNode* root){
        if(!root)return 0;
        
        int l = recur(root->left);
        int r = recur(root->right);
        
        int left = 0, right = 0;
        if(root->left && root->left->val == root->val){
            left = l+1;
        }
        
        if(root->right && root->right->val == root->val){
            right = r+1;
        }
        ans = max(ans, left+right);
        
        return max(left, right);
    }
};