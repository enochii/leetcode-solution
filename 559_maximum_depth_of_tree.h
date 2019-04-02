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

//DFS
//a little slower than DFS
class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL)return 0;
        int child_dep = 0;
        int temp_dep;
        for(unsigned i=0;i<root->children.size();i++){
            if((temp_dep =maxDepth(root->children[i]))>child_dep){
                child_dep=temp_dep;
            }
        }
        
        return child_dep+1;
    }
};


//BFS
#include <queue>

struct wrapper{
    Node* node;
    int depth;
    wrapper(Node* node, int depth):node(node),depth(depth){}
    wrapper()=default;
    wrapper(const wrapper&)=default;
};

class Solution{

std::queue<wrapper> q;

public:
    int maxDepth(Node* root){
        //clear
        //q=std::queue<wrapper>();
        if(root==NULL)return 0;
        q.emplace(root,1);

        wrapper qfront;

        while(!q.empty()){
            qfront=q.front();
            q.pop();
            auto& children= qfront.node->children;
            for(int i =0;i<children.size();i++){
                if(children[i]==NULL)continue;
                q.emplace(children[i],qfront.depth+1);
            }
        }
        return qfront.depth;
    }
};