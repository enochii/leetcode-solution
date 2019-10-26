/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 637. Average of Levels in Binary Tree
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(!q.empty()){
            int sz = q.size();
            double sum = 0.0;
            for(int i=0;i<sz;i++){
                auto top = q.front();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
                sum += top->val;
                q.pop();
            }
            ans.push_back(sum / sz);
        }
        return ans;
    }
};