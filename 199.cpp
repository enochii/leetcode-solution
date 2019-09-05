/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//binary tree right side view BFS bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //BFS?
        if(root==NULL)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        //
        while(!q.empty()){
            int sz=q.size();
            TreeNode* top=NULL;
            for(int i=0;i<sz;i++){
                top=q.front();q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
            ans.push_back(top->val);
        }
        return ans;
    }
};