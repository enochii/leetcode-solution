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
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,0,preorder.size());
    }
    TreeNode* build(vector<int>& pre,vector<int>& in,int ps,int is,int len){
        if(len==0)return NULL;
        int root=pre[ps];
        typedef TreeNode* ptr;
        ptr rt=new TreeNode(root);

        int i=is;
        while(in[i]!=root)i++;
        //此时is到i是左子树
        int l_len=i-is;
        rt->left=build(pre,in,ps+1,is,l_len);
        rt->right=build(pre,in,ps+1+l_len,i+1,len-1-l_len);
        return rt;
    }
};