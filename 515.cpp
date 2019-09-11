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
#include <queue>
#include <vector>

// 515. Find Largest Value in Each Tree Row
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//BFS 层次遍历

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);//root is not empty
        
        while(!q.empty()){
            int sz=q.size();
            int max_val=INT_MIN;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                max_val=max(max_val,node->val);
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};