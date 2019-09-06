/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <utility>
#include <stdlib.h>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return xixi(root)!=-1;
    }
    typedef pair<int, bool> ib;

    int xixi(TreeNode* root){
        if(root==NULL)return 0;
        int pl=xixi(root->left);
        int pr=xixi(root->right);
        //
        if(pl==-1||pr==-1||abs(pl-pr)>1)return -1;
        return max(pl,pr)+1;
    }
};