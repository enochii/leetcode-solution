/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//我想复杂了...必定是左最深+右最深
//还以为子树可能就存在直径...佛了

//对...子树可能存在直径
//所以一棵树的直径有三个取值可能：
// 右子树的直径、左子树的直径、左右子树深度和+1

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //还以为是深度，审题不清...
        // return root?1+max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)):0;
        //
        return helper(root).first;
    }
private:
    typedef pair<int,int> II;

    //返回root树中，两节点的最大距离和高度
    II helper(TreeNode* root){
        if(!root){
            return {0,0};
        }
        auto l = helper(root->left);
        auto r = helper(root->right);

        return {max(max(l.first, r.first), l.second+r.second),
            max(l.second, r.second)+1
        };
    }
};

//日，原来没错，我不学了。。。
// class Solution{
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root)return 0;
//         return depth(root->left) + depth(root->right)+2;
//     }

//     int depth(TreeNode* rt){
//         if(!rt)return -1;
//         return max(depth(rt->left),depth(rt->right))+1;
//     }
// };