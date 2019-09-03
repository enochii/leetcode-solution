// /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
// */

#include <queue>

using namespace std;
//还是上队列吧
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.empty()==false){
            int sz=q.size();
            Node head;
            Node* h=&head;
            for(int i=0;i<sz;i++){
                auto xi=q.front();q.pop();
                h->next=xi;
                h=h->next;
                if(h->left){
                    q.push(h->left);
                    q.push(h->right);
                }
            }
        }
        return root;
    }
};