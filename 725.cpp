/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 725. Split Linked List in Parts
//应该是可以扫描一遍的， 不过需要递归到最深处然后退回来
//那就第一遍计算长度， 把子链表的长度记录下来
//第二遍开始输出结果
class Solution {
    int len=0;
    int full_cnt;
    int part_len;
    // int k;
    
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        auto head = root;
        while(head){
            len++;
            head = head->next;
        }
        part_len = len / k;
        full_cnt = len - k*part_len;
        
        vector<ListNode*> res;
        recur(root, res, k);
        
        return res;
    }
    
    void recur(ListNode* cur, vector<ListNode*>& res, int k){
        if(k-- <= 0)return;
        res.push_back(cur);
        
        int act_len = part_len + (full_cnt > 0);
        
        ListNode* prev = nullptr;
        for(int i=0;i<act_len;i++){
            prev = cur;
            cur = cur->next;
        }
        
        if(prev){
            prev->next = nullptr;
        }
        full_cnt--;
        recur(cur, res, k);
    }
    
//     void recur(ListNode* node, const int k){
//         if(node!=nullptr){
//             len++;
//             recur(node->next);
//         }else{
//             part_len = len / k;
//             not_full_cnt = k - (len - k*part_len);
//         }
//     }
};