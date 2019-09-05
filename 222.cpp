/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//prefect binary tree

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int llevel=0,rlevel=0;
        
        auto tmp=root;
        while(tmp->right){
            llevel++;
            tmp=tmp->right;
        }
        tmp=root;
        while(tmp->left){
            rlevel++;
            tmp=tmp->left;
        }
        if(llevel==rlevel){
            //满二叉
            return pow(2,llevel+1)-1;
        }
        return countNodes(root->left)+
            countNodes(root->right)+1;
    }
};