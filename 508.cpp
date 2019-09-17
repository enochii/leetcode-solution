/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//hash是真的牛逼
class Solution {
    unordered_map<int,int> cnt;
    int maxcnt=0;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        //
        recur(root);
        vector<int> ret;
        for(auto & kv:cnt){
            if(kv.second==maxcnt){
                ret.push_back(kv.first);
            }
        }
        return ret;
    }
    
    int recur(TreeNode* root){
        if(root==NULL)return 0;
        int l=recur(root->left);
        int r=recur(root->right);
        
        int ret=root->val+l+r;
        int c=++cnt[ret];
        //记录当前最大的cnt
        if(c>maxcnt)maxcnt=c;
        return ret;
    }
};