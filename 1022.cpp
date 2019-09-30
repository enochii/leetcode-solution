// 1022. Sum of Root To Leaf Binary Numbers

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
    int sumRootToLeaf(TreeNode* root) {
        return recur(root, 0);
    }
    int recur(TreeNode* root, int cur){
        cur = (cur<<1)+root->val;
        if(root->left || root->right){
            int ans = 0;

            if(root->left)ans += recur(root->left, cur);
            if(root->right)ans += recur(root->right, cur);
            
            return ans;
        }else{
            return cur;
        }
    }
};