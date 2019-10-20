/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// 589. N-ary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)return {};
        
        stack<Node*> stk;
        stk.push(root);
        
        vector<int> ans;
        while(!stk.empty()){
            auto top = stk.top();stk.pop();
            ans.push_back(top->val);
            
            for(auto it = top->children.rbegin();it != top->children.rend();it++){
                stk.push(*it);
            }
        }
        
        return ans;
    }
};