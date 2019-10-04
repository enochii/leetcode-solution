/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 1028. Recover a Tree From Preorder Traversal

int convert(const string& s, int& pos){
    int ret = 0;
    while(pos < s.size() && isdigit(s[pos])){
        ret = ret * 10 + (s[pos] - '0');
        pos++;
    }
    return ret;
}

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
//         vector<pair<int, int> > nums;
        
//         int pos = 0;
//         while(pos < S.size()){
//             int level = 0;
//             while(S[pos]=='-'){
//                 pos++;
//                 level++;
//             }
//             int num = convert(s, pos);
//             vec.emplace(make_pair(level, pos))
//         }
        int pos = 0;
        return build(S, pos, -1);
    }
    
    int cnt = 0;
    TreeNode* build(string & s, int & pos, int lev){
        // cout<<'?';
        if(pos == s.size())return nullptr;
        if(cnt == -1){
            cnt=0;
            while(s[pos] == '-'){
                pos++;
                cnt++;
                // cout<<'!';
            }
        }
        //接下来的数字不会是自己的子树，return
        if(lev >= cnt)return nullptr;
        
        int ret = convert(s, pos);
        // cout<<ret<<' ';
        auto root = new TreeNode(ret);
        
        cnt = -1;
        root->left = build(s, pos, lev+1);
        root->right = build(s, pos, lev+1);
        
        return root;
    }
};