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
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL)return ans;
        //
        string cur=to_string(root->val);
        if(root->left==NULL&&root->right==NULL){
            return {cur};
        }
        
        if(root->left)recur(root->left,cur,ans);
        if(root->right)recur(root->right,cur,ans);
        
        return ans;
    }

    void recur(TreeNode* root, string cur,vector<string> &ans){
        cur.append("->");
        cur.append(to_string(root->val));
        if(root->left==NULL&&root->right==NULL){
            return ans.push_back(cur);
        }
        //
        if(root->left)recur(root->left,cur,ans);
        if(root->right)recur(root->right,cur,ans);
    }
};