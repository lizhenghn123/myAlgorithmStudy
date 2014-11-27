// Source : https://oj.leetcode.com/problems/rotate-list/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-26
/**********************************************************************************
*
* Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
* reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
*
* You must do this in-place without altering the nodes' values.
*
* For example,
* Given {1,2,3,4}, reorder it to {1,4,2,3}.
*
**********************************************************************************/
#include <stdio.h>
#include "../common/single_list.hpp"

void reorderList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return ;

	ListNode *fast = head;
	ListNode *slow = head;

	while (fast && fast->next)   //find list middle
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *pivot = slow->next;
	slow->next = NULL;           // split list from middle of list

	pivot = reverseList(pivot);  //reverse right part of list

	ListNode *cursor = head;
	ListNode *pivot_next, *cursor_next;
	while (pivot)                // insert list(pivot) to list(head)
	{
		pivot_next = pivot->next;
		cursor_next = cursor->next;
		cursor->next = pivot;
		pivot->next = cursor_next;

		cursor = cursor_next;
		pivot = pivot_next;
	}
}

void test_reorderList()
{
	if (1)
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		reorderList(p);
		printList(p);
		freeList(p);
	}
	if (1)
	{
		int a[] = { 1, 2 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		reorderList(p);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1, 2, 3, 4 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		reorderList(p);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		reorderList(p);
		printList(p);

		freeList(p);
	}
}

int main()
{
	test_reorderList();
	getchar();
}