/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>
#include <algorithm>

// using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans=INT_MIN;
public:
    //定义返回值必包含当前节点
    //所以返回给父节点调用值只能是val,val+l,val+r
    //更新值用上述值或者val+l+r
    int _(TreeNode* root) {
        if(!root)return 0;
        int l=_(root->left);
        int r=_(root->right);
        int ret=max({0, l,r})+root->val;
        ans=max({ret,ans,root->val+l+r});
        return ret;
    }
    int maxPathSum(TreeNode* root){
        _(root);
        return ans;
    }

};