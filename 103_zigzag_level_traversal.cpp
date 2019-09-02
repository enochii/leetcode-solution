/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdlib.h>
#include <vector>
#include <deque>

using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    //感觉类似层次遍历
    //只要多一个flag位就行
    //日 少了个deque的赋值，不知道内存低到哪里去了 nb
    //就是通过当前level的大小去判断，我记得做过不过忘了...
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool left_first=true;
        vector<vector<int>> ans;
        while(!dq.empty()){
            // deque<TreeNode*> nextq;
            vector<int> vals;
            // while(!dq.empty())
            int cur_level_sz=dq.size();
            for(int i=0;i<cur_level_sz;i++)
            {
                if(left_first){
                    auto cur=dq.front();dq.pop_front();
                    vals.push_back(cur->val);
                    if(cur->left)dq.push_back(cur->left);
                    if(cur->right)dq.push_back(cur->right);
                }else{
                    auto cur=dq.back();dq.pop_back();
                    vals.push_back(cur->val);
                    if(cur->right)dq.push_front(cur->right);
                    if(cur->left)dq.push_front(cur->left);
                }
            }
            // dq=nextq;
            ans.push_back(move(vals));
            left_first=!left_first;
        }
        return ans;
    }
};