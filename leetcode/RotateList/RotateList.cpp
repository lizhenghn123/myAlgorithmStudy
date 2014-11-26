// Source : https://oj.leetcode.com/problems/rotate-list/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-26

/**********************************************************************************
*
* Given a list, rotate the list to the right by k places, where k is non-negative.
*
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
*
**********************************************************************************/
#include <stdio.h>
#include "../common/single_list.hpp"

//类似于查找链表的倒数第N个节点，见removeNthFromEnd
ListNode* rotateRight(ListNode *head, int n)
{
	if (head == NULL || n == 0)
		return head;

	ListNode *fast = head;
	for (int i = 0; i < n; ++i)
	{
		if (fast == NULL)     // may be n > length(head), research from head
			fast = head;
		fast = fast->next;
	}

	ListNode *slow = head;
	while (fast && fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}

	if (fast == NULL)
		return head;

	fast->next = head;
	ListNode *newhead = slow->next;
	slow->next = NULL;

	return newhead;
}

int main()
{
	if (1)
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = rotateRight(p, 2);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = rotateRight(p, 99);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1, 2 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = rotateRight(p, 3);
		printList(p);

		freeList(p);
	}
	getchar();
}