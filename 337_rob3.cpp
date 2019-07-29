/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class _Solution {
    map<pair<TreeNode*, bool>, int> mem;
public:
    int rob(TreeNode* root) {
        return recur(root, true);
    }

    int recur(TreeNode* root, bool have){
        pair<TreeNode*, bool> key = {root, have};
        if(mem.count(key))return mem[key];
        if(!root)return 0;

        //
        int no_root = recur(root->left, true)+recur(root->right, true);
        int val = have?(max(root->val+recur(root->left, false)+recur(root->right, false), 
                        no_root)):no_root;

        return mem[key] = val;
    }
};

class Solution{
public:
    int rob(TreeNode* root) {
        auto ret = recur(root);
        return max(ret.first, ret.second);
    }

    typedef pair<int, int> II;

    II recur(TreeNode* root){
        if(!root)return {0,0};

        //
        auto l = recur(root->left);
        auto r = recur(root->right);
        int rob_this = root->val+l.second+r.second;
        int not_rob_thos = max(l.first,l.second)+max(r.first,r.second);
        return {
            rob_this, not_rob_thos
        };
    }
};