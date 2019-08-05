/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class _Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        
        return ans;
    }
    
    void inorder(TreeNode* rt, vector<int>& ans){
        if(!rt)return;
        inorder(rt->left,ans);
        ans.push_back(rt->val);
        inorder(rt->right,ans);
    }
};

//迭代,在while循环维持一个循环不变量
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        //
        while(root){
            stk.push(root);root=root->left;
        }
        //不变量:while开始时top()都没有左孩子
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            ans.push_back(cur->val);
            handle(cur->right,stk);
        }
        return ans;
    }
    
    void handle(TreeNode* root, stack<TreeNode*> & stk){
        while(root){
            stk.push(root);root=root->left;
        }
    }
};