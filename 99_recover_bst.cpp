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
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//16 ms
//17.5 MB
//把树存成数组的进化版，事实上比较过程中在dfs的过程中比较当前的两个节点就行
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root){
            return;
        }
        traversal(root);
        
        swap(first->val, second->val);
    }
private:
    typedef TreeNode* xi;
    // vector<TreeNode*> vec;
    xi it = NULL, first = NULL, second;

    //这玩意其实不是常量空间...除非走个尾递归
    //space :O(h)
    void traversal(TreeNode* root){
        if(root->left){
            traversal(root->left);
        }
        
        if(it && it->val > root->val){
            if(!first){
                first = it;
            }
            second = root;
        }

        if(root->right){
            traversal(root->right);
        }
    }
};

//傻逼存法，把树变成数组
class _Solution {
public:
    void recoverTree(TreeNode* root) {
        if(!root){
            return;
        }
        traversal(root);
        //
        TreeNode *tn1=0, *tn2=0;
        vector<int> swaps;
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i]->val>vec[i+1]->val){
                swaps.push_back(i);
                swaps.push_back(i+1);
            }
        }
        if(swaps.size()<4){
            swap(vec[swaps[0]]->val,vec[swaps[1]]->val);
        }else{
        swap(vec[swaps[0]]->val,vec[swaps[3]]->val);            
        }
    }
private:
    vector<TreeNode*> vec;
    
    void traversal(TreeNode* root){
        if(root->left){
            traversal(root->left);
        }
        vec.push_back(root);
        if(root->right){
            traversal(root->right);
        }
    }
};