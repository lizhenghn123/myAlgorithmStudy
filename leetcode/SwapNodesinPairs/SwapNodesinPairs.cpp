// Source : https://oj.leetcode.com/problems/linked-list-cycle/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-27
/**********************************************************************************
*
* Given a linked list, swap every two adjacent nodes and return its head.
*
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
*
* Your algorithm should use only constant space. You may not modify the values in the list,
* only nodes itself can be changed.
*
**********************************************************************************/
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"

// 前后两两交换
ListNode* swapPairs(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode dummy(0);
	ListNode *cursor = &dummy;

	ListNode *curr = head;
	ListNode *next = head->next;
	while (curr && next)
	{
		cursor->next = next;
		curr->next = next->next;
		next->next = curr;
		cursor = curr;

		curr = curr->next;
		if (curr && curr->next)
			next = curr->next;
		else
			next = NULL;
	}

	return dummy.next;
}
void test_swapPairs()
{
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 1, 2, 3 };
	int c[] = { 1, 2 };
	int d[] = { 1 };
	ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
	ListNode *p2 = createList(b, sizeof(b) / sizeof(b[0]));
	ListNode *p3 = createList(c, sizeof(c) / sizeof(c[0]));
	ListNode *p4 = createList(d, sizeof(d) / sizeof(d[0]));

	ListNode *p = swapPairs(p1);
	printList(p);

	p = swapPairs(p2);
	printList(p);

	p = swapPairs(p3);
	printList(p);

	p = swapPairs(p4);
	printList(p);
}

int main()
{
	test_swapPairs();
	getchar();
}