#pragma once

#include <cstdlib>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p1 = l1->next;
		//= reverseList(l1);
		ListNode* p2 = l2->next;
		//= reverseList(l2);

		//we need to create a new list returned
		int sum = l1->val + l2->val;
		ListNode* head = new ListNode(sum % 10);
		ListNode* current = head;
		bool up = sum >= 10 ? true : false;
		while (p1 != NULL && p2 != NULL) {
			//last operation
			int sum = p1->val + p2->val;
			if (up) {
				++sum;
			}

			up = sum >= 10 ? true : false;
			current->next = new ListNode(sum % 10);

			current = current->next;

			p1 = p1->next;
			p2 = p2->next;
		}
		while (p1 != NULL) {
			int sum = p1->val + (up ? 1 : 0);
			up = sum >= 10 ? true : false;

			current->next = new ListNode(sum % 10);
			current = current->next;

			p1 = p1->next;
		}
		while (p2 != NULL) {
			int sum = p2->val + (up ? 1 : 0);
			up = sum >= 10 ? true : false;

			current->next = new ListNode(sum % 10);
			current = current->next;


			p2 = p2->next;
		}
		if (up)
		{
			ListNode* temp = new ListNode(1);
			current->next = temp;
		}

		return head;
	}
};