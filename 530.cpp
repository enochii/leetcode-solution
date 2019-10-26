/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 530. Minimum Absolute Difference in BST
//中序遍历
//从左边向上回溯要把值往上传！所以用 reference
class Solution {
    int ans;
public:
    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        int val = -1;
        inorder(root,val);
        return ans;
    }
    
    void inorder(TreeNode* root, int& val){
        if(!root)return;
        
        inorder(root->left, val);
        if(val != -1)ans = min(ans, root->val - val);
        val = root->val;
        inorder(root->right,val);
    }
};