/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 814. Binary Tree Pruning
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
         //后序遍历
        if(postorder(root))return nullptr;
        return root;
    }
    
    bool postorder(TreeNode* root){
        if(!root)return true;
        
        //左右两个子树是否不包含1
        bool l = postorder(root->left);
        bool r = postorder(root->right);
        
        //如果左右满足并且root->val!=1那么整棵树需要被删除
        if(l && r && root->val == 0)return true;
        //
        if(l && root->left){
            //delete 0好像也没啥问题
            //不delete少用了0.5MB........
            // delete root->left;
            root->left = nullptr;
        }
        
        if(r && root->right){
            // delete root->right;
            root->right = nullptr;
        }
        //
        return false;
    }
};