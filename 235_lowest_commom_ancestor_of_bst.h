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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //let the p be the smaller/left one, just need to swap the ptr
        if(p->val>q->val)std::swap(p,q);

        for(;;){
            if(root->val<p->val)root = root->right;
            else if(root->val>q->val)root = root->left;
            else return root;
        }
        //return NULL;
    }
};