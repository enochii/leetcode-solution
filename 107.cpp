/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Binary Tree Level Order Traversal II

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*> q;q.push(root);
        vector<vector<int>> ans;
        bfs(q,ans);
        return ans;
    }
    
    void bfs(queue<TreeNode*> &q, vector<vector<int>>& ans){
        if(q.empty())return;
        
        const int sz=q.size();
        vector<int> cur(sz);
        
        for(int i=0;i<sz;i++){
            auto p=q.front();
            q.pop();
            cur[i]=p->val;
            if(p->left)q.push(p->left);
            if(p->right)q.push(p->right);
        }
        
        bfs(q,ans);
        ans.push_back(cur);
    }
};