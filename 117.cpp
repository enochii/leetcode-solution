///*
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
//*/
//117. Populating Next Right Pointers in Each Node II
//O(1) Space

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)return nullptr;
        //撸一个常量的level traversal
        Node node(-1,nullptr,nullptr,root);
        // auto head=&node;
        int cnt=1;
        //我感觉就是自己用node和cnt以及自带的next指针模拟了一个队列
        //hhhhhhhh
        while(cnt){
            //
            Node* last_level=node.next;
            Node* head=&node;
            const int cur_level=cnt;
            cnt=0;
            for(int i=0;i<cur_level;i++){
                // ch=head->next;
                if(last_level->left){
                    head->next=last_level->left;
                    head=head->next;
                    cnt++;
                }
                if(last_level->right){
                    head->next=last_level->right;
                    head=head->next;
                    cnt++;
                }
                last_level=last_level->next;
            }
            
        }
        return root;
    }
};