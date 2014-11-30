// Source : https://oj.leetcode.com/problems/partition-list/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given a linked list and a value x, partition it such that all nodes less than x come
* before nodes greater than or equal to x.
*
* You should preserve the original relative order of the nodes in each of the two partitions.
*
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
*
**********************************************************************************/
#include <stdio.h>
#include <time.h>
#include "../common/single_list.hpp"

ListNode *partition(ListNode *head, int x)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode mindummy(0);
	ListNode *cursor_min = &mindummy;

	ListNode maxdummy(0);
	ListNode *cursor_max = &maxdummy;

	ListNode dummy(0);
	dummy.next = head;
	ListNode *p_prev = &dummy;
	ListNode *p = head;
	while (p)
	{
		if (p->val < x)
		{
			p_prev->next = p->next;
			p->next = NULL;
			cursor_min->next = p;
			cursor_min = p;
			p = p_prev->next;
		}
		else
		{
			ListNode *p_next = p->next;
			p->next = NULL;
			cursor_max->next = p;
			cursor_max = p;
			p = p_next;
		}
	}
	cursor_min->next = maxdummy.next;
	return mindummy.next;
}

void test_partition()
{
	{
		int a[] = { 1, 4, 3, 2, 5, 2 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);
		printList(partition(p, 3));
		printf("------------------------\n");
	}
}

int main()
{
	test_partition();

	getchar();
}