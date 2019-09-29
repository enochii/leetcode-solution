/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 623. Add One Row to Tree
//BFS
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            auto nroot = new TreeNode(v);
            nroot->left = root;
            
            return nroot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        int dep = 1;
        while(!q.empty()){
            if(++dep == d)break;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop();
                if(top->left)q.push(top->left);
                if(top->right)q.push(top->right);
            }
        }
        //
        while(!q.empty()){
            auto top = q.front();q.pop();
            auto l = new TreeNode(v);
            auto r = new TreeNode(v);
            
            l->left = top->left;
            r->right = top->right;
            top->left = l;
            top->right = r;
        }
        return root;
    }
};