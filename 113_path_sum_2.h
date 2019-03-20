#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *    a TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//一开始想到或许可以通过判值是否过大剪枝，但题目并没有指出是非负整数
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        dfs(root,sum,0,path,ans);
        return ans;
    }
    void dfs(TreeNode* cur, const int expect, int res, vector<int>& curPath,
    vector<vector<int> > &ans){
        if(cur==NULL){
            return;
        }
        //压入
        curPath.push_back(cur->val);
        res += cur->val;
        if(cur->left==NULL&&cur->right==NULL){
            //到达叶节点，判断是否符合条件
            if(expect == res)ans.push_back(curPath);
        }
        
        dfs(cur->left, expect, res,curPath,ans);
        dfs(cur->right,expect,res,curPath,ans);
        //回退
        curPath.pop_back();
    }
};