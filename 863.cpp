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
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//通过一个map把树变成一个图(因为这个sb树没办法直接走到父节点)
//这样我们在某个节点就可以向子节点和父节点进发
//有个点是要注意不要走回头路

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*,TreeNode*> fa;
        searchfa(fa,root);//root is not empty
        searchfa(fa,root);
        seek(fa,target,NULL,K);
        return ans;
    }
    vector<int> ans;
    void searchfa(unordered_map<TreeNode*,TreeNode*>& fa, TreeNode* root){
        // if(root==NULL)return;
        if(root->left){
            fa[root->left]=root;
            searchfa(fa,root->left);
        }
        if(root->right){
            fa[root->right]=root;
            searchfa(fa,root->right);
        }
    }

    void seek(unordered_map<TreeNode*,TreeNode*>& fa, TreeNode* root,
    TreeNode* last, int k){
        if(root==NULL)return;
        if(k==0){
            ans.push_back(root->val);
        }
        if(k<=0)return;
        k--;

        //不要走回头路额
        auto pa=fa[root];
        if(last!=pa)seek(fa,pa,root,k);
        if(root->left!=last)seek(fa,root->left,root,k);
        if(root->right!=last)seek(fa,root->right,root,k);

    }
};

//好像还有O(1)的解法