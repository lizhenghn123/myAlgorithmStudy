// Source : https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-28
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"

/**********************************************************************************
*
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
*
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
*
* You may not alter the values in the nodes, only nodes itself may be changed.
*
* Only constant memory is allowed.
*
* For example,
* Given this linked list: 1->2->3->4->5
*
* For k = 2, you should return: 2->1->4->3->5
*
* For k = 3, you should return: 3->2->1->4->5
*
**********************************************************************************/

// 每K个元素逆转，否则保持不变 
ListNode* reverseKGroup(ListNode *head, int k)
{
	if (head == NULL || k == 1)
		return head;

	ListNode dummy(0);
	ListNode *cursor = &dummy;

	ListNode *fast = head;
	ListNode *slow = head;
	while (fast)
	{
		for (int i = 1; i < k; ++i)   // move fast to k position first
		{
			fast = fast->next;
			if (fast == NULL)         // have no more than k elements
			{
				cursor->next = slow;
				return dummy.next;
			}
		}

		ListNode *fast_next = fast->next;
		fast->next = NULL;

		ListNode *newhead = reverseList(slow);    // reverse list

		cursor->next = newhead;
		cursor = slow;

		fast = fast_next;
		slow = fast_next;
	}

	return dummy.next;
}

void test_reverseKGroup()
{
	{
		int a[] = { 1, 2, 3, 4 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseKGroup(p1, 2);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseKGroup(p1, 2);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseKGroup(p1, 3);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseKGroup(p1, 5);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseKGroup(p1, 6);
		printList(p);
		printf("-----------------------\n");
	}
}

int main()
{
	test_reverseKGroup();
	getchar();
}