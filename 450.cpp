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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //找到右子树最小数代替
        if(!root)return nullptr;
        if(root->val==key){
            return delRoot(root);
        }
        //
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else{
            root->right=deleteNode(root->right,key);
        }
        return root;
    }
    //转化成删除根节点
    TreeNode* delRoot(TreeNode* root){
        //右子树为空的话，可以直接走一手了
        if(root->right==NULL){
            auto xi=root->left;
            root->left=NULL;
            delete root;
            return xi;
        }
        //找到右子树的最大孩子
        auto minc=root->right;
        TreeNode* prev=NULL;
        while(minc->left){
            prev=minc;
            minc=minc->left;
        }
        root->val=minc->val;
        
        //如果右子树没有左孩子
        if(prev==NULL){
            root->right=minc->right;
            minc->right=NULL;
            delete minc;
            return root;
        }
        
        //右子树存在左孩子
        //那么递归删除，并且设置指针
        //注意右子树有无左孩子指针的修改不一样
        prev->left=delRoot(minc);
        return root;
    }
};