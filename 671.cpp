/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 671. Second Minimum Node In a Binary Tree
//
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long long ret = recur(root);
        return ret == INT_MAX+1ll? -1:ret;
    }
    
    //找到比root大的最小的孩子
    //若不存在返回INT_MAX+1(有一个case是INT_MAX)
    
    //如果和root一样大就继续找子节点
    //否则就是当前子树的所求节点了
    //比较即可
    long long recur(TreeNode* root){
        if(!root->left){
            return INT_MAX+1ll;
        }
        
        auto & l = root->left, &r = root->right;
        if(l->val == r->val){
            return min(recur(l),recur(r));
        }else{
            if(l->val > r->val){
                swap(l, r);
            }
            return min((long long)r->val, recur(l));
        }
    }
};