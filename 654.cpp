// 654. Maximum Binary Tree
//Tree

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums.begin(),nums.end());
    }
    
    typedef vector<int>::iterator It;
    TreeNode* build(It beg, It end){
        if(beg == end)return nullptr;
        //
        auto max_it = max_element(beg,end);
        auto ret = new TreeNode(*max_it);
        ret->left = build(beg, max_it);
        ret->right = build(max_it+1, end);
        
        return ret;
    }
};