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
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        
        //如果仅有一颗子树非空，那么不能在这里minimum
        if(l==0&&r>0)l=r;
        else if(r==0&&l>0)r=l;
        
        return min(l,r)+1;
    }
};