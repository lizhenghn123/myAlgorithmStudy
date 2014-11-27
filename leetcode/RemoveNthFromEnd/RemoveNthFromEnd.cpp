// Source : https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-26

/**********************************************************************************
*
* Given a linked list, remove the nth node from the end of list and return its head.
*
* For example,
*
*    Given linked list: 1->2->3->4->5, and n = 2.
*
*    After removing the second node from the end, the linked list becomes 1->2->3->5.
*
* Note:
* Given n will always be valid.
* Try to do this in one pass.
*
**********************************************************************************/
#include <stdio.h>
#include <time.h>
#include "../common/single_list.hpp"

ListNode* removeNthFromEnd(ListNode *head, int n)
{
	if (head == NULL || n <= 0)
		return head;
	else if (head->next == NULL && n == 1)
		return NULL;

	ListNode *fast = head;
	for (int i = 0; i < n; ++i)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}

	ListNode *slow = head;
	ListNode *slow_prev = NULL;
	while (fast)
	{
		slow_prev = slow;
		fast = fast->next;
		slow = slow->next;
	}

	if (slow_prev)
		slow_prev->next = slow->next;
	else
		head = head->next;

	return head;
}


void test_removeNthFromEnd()
{
	{
		int a[] = { 1, 2 };// { 0, 1, 3, 5 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = removeNthFromEnd(p, 1);
		printList(p);

		freeList(p);
	}
	{
		int a[] = { 1, 2 };// { 0, 1, 3, 5 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = removeNthFromEnd(p, 2);
		printList(p);

		freeList(p);
	}
	{
		int a[] = { 0, 1, 3, 5 };// {  };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = removeNthFromEnd(p, 5);
		printList(p);

		freeList(p);
	}
}

int main()
{
	test_removeNthFromEnd();
}