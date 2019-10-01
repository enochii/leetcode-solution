/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//我走偏了....................................................................
//并且还没写出来..............................................................
//这样搞会改变树的结构
//比如 
// [2,0,4,null,null,3]
// 3
// 4
//当删除根节点后，2会变成新的根，我是个憨憨
//不过这道题也没说不能改变顺序不是吗？不过复杂度肯定爆炸吧

// class Solution {
// public:
//     TreeNode* trimBST(TreeNode* root, int L, int R) {
//         if(root==nullptr)return nullptr;
//         if(root->val > R || root->val < L)
//             return trimBST(
//                     rmRoot(root), L, R
//                     );
//         root->left = trimBST(root->left, L, R);
//         root->right = trimBST(root->right, L, R);
        
//         return root;
//     }
    
//     TreeNode* rmRoot(TreeNode* root){
//         if(root->left == nullptr)return root->right;
//         if(root->right == nullptr)return root->left;
        
//         //
//         auto newroot = root->right;
        
//         TreeNode* prev = nullptr;
//         while(newroot->left){
//             prev = newroot;
//             newroot = newroot->left;
//         }
        
//         //右子树没有左孩子
//         if(prev == nullptr){
//             newroot->left = root->left;
//             root->left = root->right = nullptr;
//             return newroot;
//         }
        
//         prev->left = rmRoot(newroot);
        
        
//         newroot->right = root->right;
//         newroot->left = root->left;

//         // use-heap-after-delete//
//         root->left = root->right = nullptr;//防止递归重复删除
        
//         return newroot;
//     }
// };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)return nullptr;
        //父节点小于L，左区间就不要了...
        if(root->val < L)return trimBST(root->right, L, R);
        if(root->val > R)return trimBST(root->left, L, R);
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
};