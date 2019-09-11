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

//513. Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);//root is not empty
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans=q.front()->val;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;
    }
};