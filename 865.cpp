/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 865. Smallest Subtree with all the Deepest Nodes
//扫描两遍
//第一遍记录最大深度
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        const int d = depth(root);
        
        return recur(d, root, 0);
    }
    
    int depth(TreeNode* root){
        if(!root)return 0;
        
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    TreeNode* recur(const int d, TreeNode* root, int cur){
        if(!root)return nullptr;
        
        if(cur == d - 1)return root;
        
        auto l = recur(d,root->left,cur+1);
        auto r = recur(d,root->right,cur+1);
        
        if(!l && !r)return nullptr;
        else if(l && r)return root;
        else if(l)return l;
        else return r;
    }
};