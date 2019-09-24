/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//可能会有重复？
class Solution_ {
public:
    int maxAncestorDiff(TreeNode* root) {
        multiset<int> st;
        int ans=0;
        maxDiff(root,ans,st);
        return ans;
    }
    
    void maxDiff(TreeNode* root, int &ans, multiset<int>& st){
        if(root==NULL)return;
        if(!st.empty()){
            ans=max({ans,abs(root->val-*st.begin()),abs(*st.rbegin()-root->val)});
        } 
        //
        st.insert(root->val);
        maxDiff(root->left,ans,st);
        maxDiff(root->right,ans,st);
        st.erase(st.find(root->val));
    }
};

class Solution {
    // int ans=0;
public:
    int maxAncestorDiff(TreeNode* root) {
        // if(!root)return 0;
        return helper(root,root->val,root->val);
    }
    
    int helper(TreeNode* root, int mx, int mn){
        if(!root)return 0;
        int ans=max(abs(mx-root->val),abs(mn-root->val));
        
        mx=max(root->val,mx);
        mn=min(root->val,mn);
        
        int l=helper(root->left,mx,mn);
        int r=helper(root->right,mx,mn);
        
        return max({l,r,ans});
    }
};