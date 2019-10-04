/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 958. Check Completeness of a Binary Tree

class Solution {
    //遇到第一个非空节点就不会有下一层，并且当前层不会再有非空节点
    //也就是接下来的节点只能是Null
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        // bool leaf = false;//是否到达叶节点层
        bool nul = false;//是否出现空节点
        
        // int expect = 1;
        
        
        while(!q.empty()){
            int sz = q.size();
    
            // if(sz  != expect){
            //     if(leaf)return false;
            //     leaf = true;
            // }
            // expect += expect;
            
            for(int i = 0;i<sz;i++){
                auto top = q.front();
                if(top->left){
                    if(nul)return false;
                    q.push(top->left);
                }else{
                    nul = true;
                }
                 
                if(top->right){
                    if(nul)return false;
                    q.push(top->right);
                }
                else{
                    nul = true;
                }
                q.pop();
            }
        }
        
        return true;
    }
};