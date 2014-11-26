// Source : https://oj.leetcode.com/problems/merge-two-sorted-lists/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-26

/**********************************************************************************
*
* Merge two sorted linked lists and return it as a new list. The new list should be
* made by splicing together the nodes of the first two lists.
*
**********************************************************************************/
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) 
{
	ListNode dummy(0);
	ListNode *head = &dummy;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			head->next = l1;
			head = l1;
			l1 = l1->next;
		}
		else
		{
			head->next = l2;
			head = l2;
			l2 = l2->next;
		}
	}

	if (l1)
		head->next = l1;
	else if (l2)
		head->next = l2;

	return dummy.next;
}

ListNode *mergeTwoLists2(ListNode* head1, ListNode* head2)
{
	ListNode *p1 = head1, *p2 = head2;

	ListNode dummy(0);

	dummy.next = p1;
	ListNode *prev = &dummy;

	while (p1 && p2)
	{
		if (p1->val < p2->val){
			prev->next = p1;
			p1 = p1->next;
			prev = prev->next;
		}
		else
		{
			prev->next = p2;
			p2 = p2->next;
			prev = prev->next;
		}
	}
	if (p2){
		prev->next = p2;
	}
	if (p1){
		prev->next = p1;
	}
	return dummy.next;
}


int main()
{
	int a[] = { 2, 2, 3, 4 };
	int b[] = { 0, 1, 3, 5 };
	ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
	ListNode *p2 = createList(b, sizeof(b) / sizeof(b[0]));

	ListNode *p = mergeTwoLists(p1, p2);
	printList(p);
	freeList(p);

	system("pause");
}