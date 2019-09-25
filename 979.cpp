/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//跟逆序输出链表的递归思路相同嗷


class Solution {
    int mv=0;
public:
    int distributeCoins(TreeNode* root) {
        // mv=0;
        down(root,nullptr);
        return mv;
    }
    
    void down(TreeNode* root, TreeNode* par){
        if(!root)return;
        down(root->left,root);
        down(root->right,root);
        //自底向上解决
        //因为自顶向下你要考虑两条路，tnl
        if(root->val>1){
            mv+=root->val - 1;
            par->val+=root->val - 1;
            
        }else if(root->val<1){
            mv+=1-root->val;
            par->val -= 1-root->val;
        }
        root->val=1;
    }
};