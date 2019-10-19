/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 889. Construct Binary Tree from Preorder and Postorder Traversal
//出现multiple answers的原因是左右子树一个为空，那么左变右、右变左都是可以的
//中序遍历避免这个问题的原因是它可以用根节点来分开左右子树
//下面的子树有一个为空默认右子树为空
class Solution {
    using It = vector<int>::iterator;
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build(pre.begin(),pre.end(),post.begin(),post.end());
    }
    
    TreeNode* build(It preb, It pree, It postb, It poste){
        if(preb == pree)return nullptr;
        
        TreeNode* root = new TreeNode(*preb);
        preb++, poste--;
        
        auto pos = postb;
        while(pos != poste && *pos++ != *preb)pos;
        
        int lc = pos-postb;
        root->left = build(preb,preb+lc, postb, pos);
        root->right = build(preb+lc, pree, pos, poste);
        
        return root;
    }
};