/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 572. Subtree of Another Tree

class Solution {
public:
    //t是否是s的子树
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t)return true;
        return isSubtree_(s, t);
    }
    bool isSubtree_(TreeNode* s, TreeNode* t) {
        if(!s)return false;
        return same(s,t) || isSubtree_(s->left, t)
            || isSubtree_(s->right, t);
    }
    
    bool same(TreeNode* s, TreeNode* t){
        if(!s)return !t;
        if(!t)return false;
        return s->val == t->val && same(s->left, t->left)
            && same(s->right, t->right);
    }
};