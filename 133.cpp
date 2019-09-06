#include <vector>
#include <unordered_map>

using namespace std;

// /*
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;

//     Node() {}

//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// */

//用map做映射，我感觉我跑偏了？
//还挺快，可以
class Solution {
public:
    typedef Node* nptr;
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<nptr,nptr> mp;
        return deepcopy(node,mp);
    }
    nptr deepcopy(Node* node,unordered_map<nptr,nptr> &mp){
        cout<<node->val;
        if(mp.find(node)!=mp.end())return mp[node];
        nptr nd=new Node(node->val,node->neighbors);
        mp[node]=nd;//注意这个的赋值要在for之前...
        for(auto& nei:nd->neighbors){
            nei=deepcopy(nei,mp);
        }
        return nd;
    }
};