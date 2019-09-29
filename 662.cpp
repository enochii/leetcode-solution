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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        int max_wid = 1;
        
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int sz = q.size();
            int width = 0;
            
            bool first = false;
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop_front();
                if(top == nullptr){
                    q.push_back(nullptr);
                    q.push_back(nullptr);
                    continue;
                }
                // if(top->left){
                //     width ++;
                    q.push_back(top->left);
                // }
                // if(top->right){
                //     width += (top->left? 1:2);
                    q.push_back(top->right);
                // }
            }
            //...
            while(!q.empty() && q.back() == nullptr)q.pop_back();
            while(!q.empty() && q.front() == nullptr)q.pop_front();
            max_wid = max(max_wid, (int)q.size());
        }
        
        return max_wid;
    }
};

//考虑到树可能十分稀疏，所以可以用hash
//后来想了下，其实只要记录非空节点就行，那就上数组
//所以一般来说是要像正常二叉树的那种索引就行了
//但是一个坑是，那样会爆炸，long long也不行
//所以我们可以做一个偏移，直接减去开头的索引就行
//这样每次index数组都是从0开始！

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        int max_wid = 1;
        
        deque<TreeNode*> q;
        q.push_back(root);
        
        // unorder_map<TreeNode*, int> mp;
        vector<int> index = {0};//存储非空节点在某个level的索引，根据这个来计算宽度
        while(!q.empty()){
            int sz = q.size();
            int width = 0;
            vector<int> lastin = index;
            index.clear();
            
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop_front();
                
                if(top->left){
                //     width ++;
                    q.push_back(top->left);
                    index.push_back((lastin[i]-lastin[0])*2);
                }
                if(top->right){
                //     width += (top->left? 1:2);
                    q.push_back(top->right);
                    index.push_back((lastin[i]-lastin[0])*2+1);
                }
            }
            //...
            //< 2宽度必定不会大于1
            if(index.size() >= 2){
                max_wid=max(max_wid, index.back()+1 - index.front());
            }
            // index.clear();
        }
        
        return max_wid;
    }
};