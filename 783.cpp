/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 783. Minimum Distance Between BST Nodes
//中序遍历
class Solution {
    int ans = INT_MAX;
public:
    int minDiffInBST(TreeNode* root) {
        int val = root->val;
        recur(root, val);
        return ans;
    }
    
    void recur(TreeNode * root, int &prev){
        if(!root)return;
        
        recur(root->left, prev);
        if(root->left){
            ans = min(ans, root->val - prev);
            // cout<<root->val << ' ' << prev<<'\n';
        }
        
        prev = root->val;
        recur(root->right, prev);
    }
};