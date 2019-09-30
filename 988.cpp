// 988. Smallest String Starting From Leaf

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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
    
    //注意加上父节点的所有值进行比较... 因为对某一结点的不等长子树，单靠
    //两颗子树是无法判断的
    //这个空间好像也没办法咋优化
    string dfs(TreeNode* root, string par){
        if(root==nullptr)return par;
        
        char c = root->val + 'a';
        par = c + par; 
        
        auto l = dfs(root->left, par);
        auto r = dfs(root->right, par);
        
        
        if(root->left == nullptr)return r;
        if(root->right == nullptr)return l;
        
        
        return min(l,r);
    }
};
