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
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//层次遍历，挺好
class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            vector<int> cur_lev;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto tn=q.front();
                cur_lev.push_back(tn->val);
                if(tn->left){
                    q.push(tn->left);
                }
                if(tn->right){
                    q.push(tn->right);
                }
                q.pop();
            }
            ans.push_back(move(cur_lev));
        }
        return ans;
    }
};

//可以用queue队列来省去递归的嘻嘻
class _Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        level(root,ans,0);
        return ans;
    }

    void level(TreeNode* root, vector<vector<int>>& ans, int lev){
        if(!root)return;
        if(lev+1>ans.size())ans.push_back({});
        ans[lev].push_back(root->val);
        level(root->left,ans,lev+1);
        level(root->right,ans,lev+1);
    }
};