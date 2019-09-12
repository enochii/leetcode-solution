// 872. Leaf-Similar Trees

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
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        preorder(root1,seq1);
        //
        vector<int> seq2;
        preorder(root2,seq2);

        return seq1==seq2;
    }

    void preorder(TreeNode* root, vector<int>& ans){
        if(root->left==nullptr&&root->right==nullptr){
            ans.push_back(root->val);
            return;
        }
        //
        if(root->left){
            preorder(root->left,ans);
        }
        if(root->right){
            preorder(root->right,ans);
        }
    }
};