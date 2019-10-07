/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 606. Construct String from Binary Tree

class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)return "";
        string s;
        s.append(to_string(t->val));
        preorder(t->left, s);
        if(!t->left && t->right){
            s.append("()");
        }
        preorder(t->right, s);
        return s;
    }
    
    void preorder(TreeNode* t, string& s){
        if(!t)return;
        s.push_back('(');
        s.append(to_string(t->val));
        preorder(t->left,s);
        if(!t->left && t->right){
            s.append("()");
        }
        preorder(t->right,s);
        
        s.push_back(')');
    }
};