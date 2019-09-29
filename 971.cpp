/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//这个题... 有点绕
//首先size是可以默认没有问题的，即节点数和元素数量相同

class Solution {
    vector<int> ans;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int pos = 0;
        if(root == nullptr)return {};
        if(voyage[pos]==root->val && recur(root, voyage,pos)){
            return ans;
        }else{
            return {-1};
        }
    }
    
    bool recur(TreeNode* root, vector<int>& voyage, int& pos){
        if(pos == voyage.size() - 1)return true;
        if(voyage[pos] != root->val)return false;//左右子树都要判断...
        //
        pos++;
        if(root->left && root->left->val == voyage[pos]){
            return recur(root->left,voyage,pos) || 
                (root->right&&recur(root->right,voyage,pos));
        }
        
        if(root->right && root->right->val == voyage[pos]){
            
            auto lret = recur(root->right,voyage,pos);
            if(root->left){
                ans.push_back(root->val);
                lret = lret || recur(root->left,voyage,pos);
            }
            return lret;
        }
        
        return false;//还没结束
    }
};