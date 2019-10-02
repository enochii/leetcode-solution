// 653. Two Sum IV - Input is a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//这是一个BST，可以push完用双指针

class _Solution {
    set<int> st;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr)return false;
        
        if(st.count(k - root->val)) return true;
        st.insert(root->val);
        
        return findTarget(root->left, k) || 
            findTarget(root->right, k);
    }
    
    
};

//利用BST的性质可以拿到一个已排序的数组，直接双指针
class Solution {
    set<int> st;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)return false;
        
        vector<int> v;
        inorder(v, root);
        //
        int l = 0, r = v.size()-1;
        while(l < r){
            int actual = v[l] + v[r];
            if(actual > k){
                r --;
            }else if(actual < k){
                l ++;
            }else return true;
        }
        return false;
    }
    
    void inorder(vector<int>& v, TreeNode* root){
        if(!root)return;
        
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
    }
};