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
// 590. N-ary Tree Postorder Traversal
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)return {};
        vector<int> ans;
        
        post(root, ans);
        return ans;
    }
    
    void post (Node* root, vector<int>& ans){
        for(auto it = root->children.begin();it!=root->children.end();it++){
            post(*it, ans);
        }
        ans.push_back(root->val);
    }
};

class _Solution {
    struct wrapper{
        Node* node;
        bool vis;
        
        wrapper(Node* node):node(node),vis(false){}
    };
public:
    vector<int> postorder(Node* root) {
        if(!root)return {};
        
        stack<wrapper> stk;
        stk.emplace(root);
        
        vector<int> ans;
        while(!stk.empty()){
            auto & top = stk.top();
            if(top.vis){
                stk.pop();
                ans.push_back(top.node->val);
            }else{
                for(auto it = top.node->children.rbegin();it!=top.node->children.rend();it++){
                    stk.emplace(*it);
                }
                top.vis = true;
            }
        }
        return ans;
    }
};