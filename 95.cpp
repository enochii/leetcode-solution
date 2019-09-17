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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <vector>

using namespace std;

//就是一个枚举吧...
//感觉题目限制有点松，不用深复制...
//然后就是懒得释放内存了--

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
        vector<vector<vector<TreeNode*>>> mem(n+1,vector<vector<TreeNode*>>(n+1));
        return build(0,n,mem);
        //其实还要释放内存的--
    }

    vector<TreeNode*>& build(int l, int r, vector<vector<vector<TreeNode*>>>& mem){
        if(mem[l][r].empty()==false){
            return mem[l][r];
        }
        vector<TreeNode*> &ret=mem[l][r];
        if(l==r){
            ret.push_back(nullptr);
            return ret;
        }
        
        for(int i=l;i<r;i++){
            auto lefts=build(l,i,mem);
            auto rights=build(i+1,r,mem);
            for(int j=0;j<lefts.size();j++){
                for(int k=0;k<rights.size();k++){
                    auto root=new TreeNode(i+1);
                    root->left=deep_copy(lefts[j]);
                    root->right=deep_copy(rights[k]);
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }

    //需要写个深复制？
    TreeNode* deep_copy(TreeNode* root){
        return root;//不用深复制...
        
        if(!root)return NULL;
        auto ret=new TreeNode(root->val);
        ret->left=deep_copy(root->left);
        ret->right=deep_copy(root->right);
        return ret;
    }
};