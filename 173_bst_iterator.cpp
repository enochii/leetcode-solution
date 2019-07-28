/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    //维护一个栈，栈顶为当前最小的节点
    //弹出一个值后需要调用helper
    //也即把右子树的根节点开始一直向左到最深的节点都进栈
    //考虑到进栈和出栈次数最多均为n(节点数量)
    //所以均摊后时间复杂度为常数
    //另外由于这个栈是动态拓展的，空间复杂度为O(h)
    
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
     void helper(TreeNode* rt){
        while(rt){
            // cout<<rt->val<<' ';
            stk.push(rt);
            rt=rt->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        auto xi  = stk.top();
        stk.pop();
        if(xi->right){
            helper(xi->right);
        }
        
        
        return xi->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */