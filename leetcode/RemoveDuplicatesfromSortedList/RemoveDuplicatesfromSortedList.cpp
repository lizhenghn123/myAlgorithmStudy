// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list/
// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-26
#include <stdio.h>
#include "../common/single_list.hpp"

/**********************************************************************************
*
* Given a sorted linked list, delete all duplicates such that each element appear only once.
*
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
*
**********************************************************************************/
ListNode* deleteDuplicates(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *currp = head;
	ListNode *nextp = head->next;
	while (currp && nextp)
	{
		if (currp->val == nextp->val)
		{
			currp->next = nextp->next;
			nextp = nextp->next;
		}
		else
		{
			currp = nextp;
			nextp = nextp->next;
		}
	}

	return head;
}

/**********************************************************************************
*
* Given a sorted linked list, delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list.
*
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
*
**********************************************************************************/
ListNode *deleteDuplicates_Distinct(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode dummy(0);
	ListNode *cursor = &dummy;

	ListNode *currp = head;
	ListNode *nextp = head->next;
	bool dup = false;   //用于确定当currp和nextp值不相同时，currp的值是否是重复出现的
	while (currp && nextp)
	{
		if (currp->val == nextp->val)
		{
			dup = true;
		}
		else
		{
			if (dup)
			{
				dup = false;
			}
			else
			{
				cursor->next = currp;
				cursor = currp;
				currp->next = NULL;
			}
		}

		currp = nextp;
		nextp = nextp->next;
	}

	if (currp && dup == false)
		cursor->next = currp;

	return dummy.next;
}

int main()
{
	if (1)
	{
		int a[] = { 1, 1, 1, 2, 3 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = deleteDuplicates_Distinct(p);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1, 2, 3, 3, 4, 4, 5 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = deleteDuplicates_Distinct(p);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1, 1 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = deleteDuplicates_Distinct(p);
		printList(p);

		freeList(p);
	}
	if (1)
	{
		int a[] = { 1, 2, 2 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);

		p = deleteDuplicates_Distinct(p);
		printList(p);

		freeList(p);
	}
	getchar();
}