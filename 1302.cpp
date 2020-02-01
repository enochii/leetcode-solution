/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//bfs
//calculate sum of each level from top to bottom
// the final result is the ans
// T : O(n)
// M : O(n)
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        
        int res = 0;//int 够了
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int level_sz = q.size();
            
            res = 0;
            
            for(int i = 0;i<level_sz;i++)
            {
                auto cur = q.front();
                res += cur->val;
                
                q.pop();

                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
            
        }
        return res;
    }
};