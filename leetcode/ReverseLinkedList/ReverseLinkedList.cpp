// Source : https://oj.leetcode.com/problems/reverse-linked-list-ii/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-28
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"

/**********************************************************************************
*
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
*
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
*
* return 1->4->3->2->5->NULL.
*
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
*
**********************************************************************************/

// 逆转[m,n]之间的元素
ListNode *reverseBetween(ListNode *head, int m, int n)
{
	if (head == NULL || m >= n)
		return head;

	ListNode dummy(0);
	dummy.next = head;

	ListNode *fast = head;
	ListNode *fast_prev = &dummy;

	int difference = n - m;
	for (int i = 0; i < difference; ++i)
	{
		if (fast == NULL)
			return NULL;
		fast_prev = fast;
		fast = fast->next;
	}

	ListNode *slow = head;
	ListNode *slow_prev = &dummy;
	for (int i = 1; i < m; ++i)
	{
		slow_prev = slow;
		slow = slow->next;

		fast_prev = fast;
		fast = fast->next;
	}

	ListNode *fast_next = fast->next;        // save right of list
	fast->next = NULL;
	slow_prev->next = NULL;                  // split left of list

	ListNode *newlist = reverseList(slow);   // reverse middle of list

	slow_prev->next = newlist;
	slow->next = fast_next;                  // now slow is unchanged, and slow == tail(newlist)

	return dummy.next;                       //mention : dummy.next == head or not(m == 1) 
}

void test_reverseBetween()
{
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseBetween(p1, 2, 4);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseBetween(p1, 3, 4);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseBetween(p1, 1, 5);
		printList(p);
		printf("-----------------------\n");
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p1);

		ListNode *p = reverseBetween(p1, 1, 3);
		printList(p);
		printf("-----------------------\n");
	}
}

int main()
{
	test_reverseBetween();
	getchar();
}