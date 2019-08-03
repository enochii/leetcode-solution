/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdlib>
#include <utility>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//为什么你们的map这么熟练？
//保存祖先路径的和
//相减可以得到一段路径的和...
//又是那个两数之和的变形
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int ans = 0;
        map<int, int> mem;
    }
    
    void _(TreeNode* root, const int sum,int cur, int&ans,map<int,int>& mem){
        if(!root){
            return;
        }
        cur+=root->val;
        if(mem.count(cur-sum)){
            ans+=mem[cur-sum];
        }
        mem[cur]++;
        _(root->left,sum,cur,ans,mem);
        _(root->right,sum,cur,ans,mem);
        mem[cur]--;
    }
};