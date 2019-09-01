/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//直接中序遍历就可以了吧
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // if(root==NULL)return NULL;
        traversal(root, k);
        return ans;
    }
    
    int cnt=0;
    int ans=-1;
    void traversal(TreeNode* root, int k){
        if(cnt==k||root==NULL)return;
        traversal(root->left,k);
        if(++cnt==k){
            ans=root->val;
        }
        traversal(root->right,k);
    }
};