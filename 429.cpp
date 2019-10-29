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
// 429. N-ary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        
        vector<vector<int>> ans ;
        queue<Node* > q;
        q.push(root);
        while(!q.empty()){
            ans.push_back({});
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto top = q.front();
                for(auto child : top->children){
                    q.push(child);
                }
                ans.back().push_back(top->val);
                q.pop();
            }
        }
        return ans;
    }
};