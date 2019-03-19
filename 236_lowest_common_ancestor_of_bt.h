#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution_ {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> pa,qa;//ancestors of p and q
        
        recordAncestor(root,p,pa);
        recordAncestor(root,q,qa);

        size_t pa_sz = pa.size(), qa_sz = qa.size();
        size_t i = 1;
        for(;i <= pa_sz && i <= qa_sz && pa[pa_sz - i]==qa[qa_sz - i];++i);

        return pa[pa_sz - i+1];
    }

    //向下搜索，同时将路径上的val压入v
    bool recordAncestor(TreeNode* root, TreeNode* p, std::vector<TreeNode*>& v){
        if(root == p){
            //把自己也压进去，便于处理边界条件
            v.push_back(root);
            return true;
        }
        else if(root == NULL)return false;
        //如果p是root的左右子孙(不包括自身)，那么root在路径上
        else if(recordAncestor(root->left,p,v)){
            v.push_back(root);
            return true;
        }
        else if(recordAncestor(root->right,p,v)){
            v.push_back(root);
            return true;
        }
        else return false;
    }
};

//更为机智的solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //搜索到 p 或者 q 就返回当前的root
        if(root == NULL || p == root || q == root)return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //如果left和right均不为空，那么此时的root便是LCA
        //left和right均为空，那么root不符合条件，返回NULL
        //1空1不空，那么把不空的子孙传上去
        
        //这个过程大概是先深搜，再回溯
        return left != NULL? (right != NULL? root:left):right;
    }
};