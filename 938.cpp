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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)return 0;
        int cur=0;
        if(root->val >= L && root->val <= R)cur+=root->val;
        return rangeSumBST(root->left,L,R)+rangeSumBST(root->right,L,R)+cur;
    }
    
//     int sum(TreeNode* root, int L, int R){
        
//     }
};