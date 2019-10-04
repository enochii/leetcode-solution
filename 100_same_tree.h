struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Same Tree.
//Memory Usage: 10.2 MB, less than 51.25% of C++ online submissions for Same Tree.


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
    //可参考symmetric tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL)return q==NULL;
        else return q!=NULL
            && p->val == q->val
            && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
    }
};