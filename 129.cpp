/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        return recur(root,0);
    }

    int recur(TreeNode* root, int val){
        val=val*10+root->val;
        if(!root->left&&!root->right)return val;
        //不是叶节点
        int sum=0;
        if(root->left)sum+=recur(root->left,val);
        if(root->right)sum+=recur(root->right,val);
        return sum;
    }
};