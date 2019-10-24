/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1019. Next Greater Node In Linked List
//看起来应该从前往后搜索
//假设 i < j, j = i+1, i+2...
//那么如果node_i->val < node_j->val，那么next[i] = j
//否则i就可以从next[j]开始搜索，因为<j.val必定 < i.val
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* nextGreater = nullptr;//当前搜到的next greater num
        
        vector<ListNode*> stk;
        auto p = head;
        while(p){
            stk.push_back(p);
            p=p->next;
        }
        int n = stk.size();
        vector<int> ans(n,0);
        for(int i = n-2;i>=0;i--){
            for(int j = i+1;j<n && j>0;){//记得>0，不然会有可能死循环
                //
                if(stk[i]->val > stk[j]->val){
                    j = ans[j];
                    continue;
                }else if(stk[i]->val == stk[j]->val){
                    ans[i] = ans[j];
                }else{
                    ans[i] = j;
                }
                break;
                //
            }
        }
        for(int &index : ans){
            if(index)index = stk[index]->val;
        }
        return ans;
    }
};