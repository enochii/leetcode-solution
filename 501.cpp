// 501. Find Mode in Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class _Solution {
    unordered_map<int, int> mp;

public:
    vector<int> findMode(TreeNode* root) {
        recur(root);
        int cnt = 0;
        for(auto it = mp.begin();it!=mp.end();it++){
            cnt = max(cnt, it->second);
        }
        vector<int> ans;
        for(auto it = mp.begin();it!=mp.end();it++){
           if(it->second == cnt){
               ans.push_back(it->first);
           }
        }
        return ans;
    }
    
    void recur(TreeNode* root){
        if(!root)return;
        mp[root->val]++;
        recur(root->left);
        recur(root->right);
    }
};

//看了题解还没想到可以有序遍历，tql
class Solution{
public:
    vector<int> findMode(TreeNode* root) {
        if(!root)return {};
        collect = false;
        cnt = maxcnt = 0;
        
        inorder(root);
        maxcnt = max(cnt, maxcnt);//mode可能是最大的树

        collect = true;
        cnt =0;
        inorder(root);
        if(cnt == maxcnt)ans.push_back(val);//mode可能是最大的树
        
        return ans;
    }
    
    int val,cnt, maxcnt;
    bool collect;
    vector<int> ans;
    
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(root->val == val){
            cnt++;
        }else{
            if(!collect)maxcnt = max(cnt, maxcnt);
            else if(maxcnt==cnt)ans.push_back(val);
            val = root->val;
            cnt = 1;
        }
        inorder(root->right);
    }
};