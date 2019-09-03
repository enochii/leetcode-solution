/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//无脑递归
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums.begin(),nums.end());
    }
    
    typedef vector<int>::iterator vit;
    TreeNode* build(vit beg, vit end){
        if(beg==end)return NULL;
        const int sz=end-beg;
        auto mid=beg+sz/2;
        TreeNode* root=new TreeNode(*mid);
        root->left=build(beg,mid);
        root->right=build(mid+1,end);
        
        return root;
    }
};