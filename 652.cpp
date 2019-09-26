/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//编码 
//HashTable
//652 
class Solution {
    vector<TreeNode*> ret;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
       //初步想法是把每一个子树都编码进某个map里面嗷
        //新加入一颗子树就判断下
        unordered_map<string, TreeNode*> mp;
        encode(root,mp);
        return ret;
    }
    
    string encode(TreeNode* root, unordered_map<string, TreeNode*> & mp){
        if(!root)return "n";
        string ans=to_string(root->val);
        ans.push_back(' ');
        //
        ans += encode(root->left,mp);
        ans += encode(root->right,mp);
        
        auto it=mp.find(ans);
        if(it!=mp.end()&&it->second){
            ret.push_back(it->second);
            it->second=NULL;
        }
        else{
            mp.emplace(ans,root);
        }
        return ans;
    }
};