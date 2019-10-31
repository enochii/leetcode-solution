/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 897. Increasing Order Search Tree
class _Solution {
    TreeNode* ret;
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        ret = nullptr;
        recur(root, pre);
        return ret;
    }
    
    //引用是为了 “返回”
    void recur(TreeNode* cur, TreeNode* &pre){
        if(!cur)return;
        
        recur(cur->left, pre);
        if(pre){//or pre
            pre->left = nullptr;
            pre->right = cur;
            cur->left = nullptr;//!
        }else{
            ret = cur;
        }
        pre = cur;
        cout << pre->val<<' ';
        recur(cur->right, pre);
    }
};

//逆着来，就不用做if何root赋值了，prev就是新的root
//只快了8ms...
class Solution {
public:
    void recur(TreeNode* cur, TreeNode* &pre){
        if(!cur)return;
        
        recur(cur->right, pre);
        cur->right = pre;
        if(pre){
            pre->left = nullptr;
        }
        pre = cur;
        recur(cur->left, pre);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* prev = NULL;
        recur(root, prev);
        return prev;
    }
};