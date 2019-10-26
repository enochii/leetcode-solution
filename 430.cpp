/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
// 430. Flatten a Multilevel Doubly Linked List
class Solution {
public:
    Node* flatten(Node* head) {
        // Node dummy(-1,0,0,0);//注意初始化，或者直接在这里判断 head!=nullptr
        if(!head)return nullptr;
        Node dummy;
        Node* sb = &dummy;
        
        // Node* p = nullptr;
        stack<Node*> nexts;
        while(head || !nexts.empty()){
            if(!head){
                head = nexts.top();
                nexts.pop();
            }
            
            sb->next = head;
            head->prev = sb;
            sb = sb->next;
            
            if(head->child){
                if(head->next){
                    nexts.push(head->next);
                    // cout << head->next->val<<' ';
                }
                auto tmp = head->child;
                head->child = nullptr;
                head = tmp;
            }else{
                head = head->next;
            }
        }
        if(dummy.next!=nullptr){
            dummy.next->prev = nullptr;
        }
        return dummy.next;
    }
};