/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//时间复杂度：O(n)
//连续和的套路
//发现出现相同的sum就把中间的那部分erase掉
//有一个问题是去除部分还有信息残留，比如 1 2 3 -2 -3 5 5 -5 1
//那么去除2 3 -2 -3后3的信息会对后面的产生影响，所以我们把去除的2 3 -2 -3全部标记为invalid
//到第一个5就可以更新mp[6]的值

// 1171. Remove Zero Sum Consecutive Nodes from Linked List
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        auto dummy = ListNode(-1);
        dummy.next = head;
        auto sb = &dummy;
        
        unordered_map<int, ListNode*> mp;
        unordered_set<ListNode*> invalid;
        
        mp[0] = sb;
        int sum = 0;
        while(head){
            sum += head->val;
            
            if(mp.count(sum) && !invalid.count(mp[sum])){
                auto pre = mp[sum];
                
                for(auto p=pre->next;p!=head->next;p=p->next){
                    invalid.insert(p);
                }
                mp[sum]->next = head->next;
            }else{
                mp[sum] = head;
            }
            
            head = head->next;
        }
        
        return dummy.next;
    }
};