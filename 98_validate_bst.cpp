/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdio>
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//用孩子来限制父节点的做法有点蠢
//Runtime：16ms
//Memory Usage: 20.5MB
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return _isValidBST(root);
    }
private:
    inline bool _isValidBST(TreeNode* root) {
        //需要检查左子树的最大孩子小于自己
        //同理检查右子树的最小孩子大于自己
        TreeNode* max_lc = root->left;
        
        if(max_lc!=NULL){
            while(max_lc->right!=NULL){
            max_lc=max_lc->right;
            }
            if(max_lc->val>=root->val){
                return false;
            }
        }
        
        TreeNode* min_rc = root->right;
        if(min_rc != NULL){
            while(min_rc->left!=NULL){
            min_rc = min_rc->left;
            // self = false;
            }
            if(min_rc->val<=root->val){
                return false;
            }
        }
        
        return (root->left==NULL||root->left->val<root->val)
            && (root->right==NULL||root->right->val>root->val)
            && isValidBST(root->left)
            && isValidBST(root->right);
    }
};

//用父亲来限制孩子
//12 ms, 20.4 MB
class _Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        return _isValidBST(root,LLONG_MAX, LLONG_MIN);
    }
private:
    inline bool _isValidBST(TreeNode* root, long long _max, long long _min) {
        return root->val < _max && root->val > _min
            && (root->left == NULL || (_isValidBST(root->left, root->val, _min)))
            && (root->right == NULL || (_isValidBST(root->right, _max, root->val)));
    }
};