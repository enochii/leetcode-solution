/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1110. Delete Nodes And Return Forest
//有点意思

class Solution {
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) 
    {
        del(root, to_delete, nullptr, true);
        return ans;
    }
    
    void del(TreeNode* root, vector<int>& to_delete, TreeNode* fa, bool left)
    {
        if(!root)
        {
            return;
        }
        
        for(int td: to_delete)
        {
            if(td == root->val)
            {
                del(root->left, to_delete, nullptr, true);
                del(root->right, to_delete, nullptr, false);
                root->left = root->right = nullptr;//防止重复删除
                // delete root;
                //不能delete，根节点 server那边好像会帮我们delete一手
                // [1,2,3,null,null,null,4]
                // [2,1]
                
                if(fa != nullptr)
                {
                    //断开父节点和自己的联系
                    left?(fa->left = nullptr) : (fa->right = nullptr);
                }
                return;
            }
        }
        //保留当前节点
        if(!fa)ans.push_back(root);
        del(root->left, to_delete, root, true);
        del(root->right, to_delete, root, false);
    }
};