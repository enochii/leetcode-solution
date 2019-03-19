struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isEqual(root->left, root->right);
    }
private:
    bool isEqual(TreeNode* left, TreeNode* right){
        if(left==NULL)return right == NULL;
        else if(right==NULL)return false;
        else return left->val == right->val
        && isEqual(left->left,right->right)
        && isEqual(left->right,right->left);
    }
};