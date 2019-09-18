/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // TreeNode xi;
public:
    vector<int> postorderTraversal(TreeNode* root) {

        //疯狂压left
        //没有left就压right
        //直到
        stack<TreeNode*> stk;
        vector<int> ans;
        push(root,stk);
        //
        while(stk.empty()==false){
            auto top=stk.top();
            // stk.pop();
            if(
               top->right!=NULL){
                push(top->right,stk);
                
                top->right=NULL;//这里直接把原树修改了-- 当然也可以new个Node。
            }else{
                stk.pop();
                ans.push_back(top->val);
            }
        }
        return ans;
    }
    void push(TreeNode* root,stack<TreeNode*>& stk){
        if(!root)return;
        stk.push(root);
        while(root->left){
            root=root->left;
            stk.push(root);
        }
    }
};