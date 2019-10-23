/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//894. All Possible Full Binary Trees
//有些可以浅复制，有些不行
//区别在于是否会改变其内部结构

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N == 0)return {};
        vector<vector<TreeNode*>> fulls(1+N);
        fulls[0].push_back(nullptr);
        fulls[1].push_back(new TreeNode(0));
        
        build(fulls, N);
        return fulls.back();
    }
    
    void build(vector<vector<TreeNode*> > &fulls, int n){
        if((n&1)==0 || !fulls[n].empty())return;
        
        n--;
        for(int i=0;i<n/2;i+=2){
            
            int l = i+1, r = n - i - 1;
            build(fulls, l);
            build(fulls, r);
            for(auto lc : fulls[l]){
                for(auto rc : fulls[r]){
                    auto root = new TreeNode(0);
                    root->left = lc;//shallow copy
                    root->right = rc;
                    fulls[n+1].push_back(root);
                    
                    if(l == r)continue;
                    root = new TreeNode(0);
                    root->left = rc;
                    root->right = lc;
                    fulls[n+1].push_back(root);
                }
            }
        }
        
    }
};