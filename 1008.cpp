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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //第一个是根，然后找到第一个比自己大的数，左右砍开
        //递归解决
        return build(preorder.begin(),preorder.end());
    }
    
    template <typename It>
    TreeNode* build(It first, It last){
        if(first==last)return nullptr;
        auto root= new TreeNode(*first);
        // cout<<*first<<' ';
        
        auto it=++first;
        for(;it!=last&&*it<root->val;it++);
        auto ln=build(first,it);
        auto rn=build(it,last);
        
        root->left=ln;
        root->right=rn;
        
        return root;
    }
};