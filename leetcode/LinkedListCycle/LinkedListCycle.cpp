// Source : https://oj.leetcode.com/problems/linked-list-cycle/
// Source : https://oj.leetcode.com/problems/linked-list-cycle-ii/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-27
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"

/**********************************************************************************
*
* Given a linked list, determine if it has a cycle in it.
*
* Follow up:
* Can you solve it without using extra space?
*
**********************************************************************************/
bool hasCycle(ListNode *head)
{
	if (head == NULL)
		return false;

	ListNode *fast = head;
	ListNode *slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}

	return false;
}

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
//判断有环时记下交点。从交点处计算环长N。接下来就是从表头查找倒数第N个点。
ListNode* detectCycle(ListNode *head)
{
	if (head == NULL)
		return NULL;

	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *inters = NULL;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			inters = fast;
			break;
		}
	}

	if (inters == NULL)         //无交点
		return NULL;
	else if (inters == head)    //交点==表头
		return head;

	int len = 1;                //计算环长
	ListNode *p = inters->next;
	while (p != inters)
	{
		p = p->next;
		len += 1;
	}

	//从链表表头查找倒数第N个节点
	if (len == 1)
		return inters;

	fast = head;
	for (int i = 0; i < len; ++i)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}

	slow = head;
	while (fast)
	{
		if (fast == slow)
			return slow;
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}

void test_hasCycle()
{
	int a[] = { 1, 2, 3, 4 };
	int b[] = { 1, 2, 3 };
	int c[] = { 1, 2 };
	int d[] = { 1 };
	ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));
	ListNode *p2 = createList(b, sizeof(b) / sizeof(b[0]));
	ListNode *p3 = createList(c, sizeof(c) / sizeof(c[0]));
	ListNode *p4 = createList(d, sizeof(d) / sizeof(d[0]));

	printf("%d\n", hasCycle(p1));
	printf("%d\n", hasCycle(p2));
	printf("%d\n", hasCycle(p3));
	printf("%d\n", hasCycle(p4));
}

void test_detectCycle()
{
	{
		int a[] = { 1, 2 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));

		ListNode *s = p1;
		ListNode *e = p1->next;
		e->next = s;

		ListNode *inters = detectCycle(p1);
		if (inters)
			printf("get intersect %d\n", inters->val);
	}
	{
		int a[] = { 1, 2, 3, 4, 5 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));

		ListNode *s = p1->next->next;
		ListNode *e = p1->next->next->next->next;
		e->next = s;

		ListNode *inters = detectCycle(p1);
		if (inters)
			printf("get intersect %d\n", inters->val);
	}
	{
		int a[] = { 1, 2 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));

		ListNode *s = p1->next;
		ListNode *e = s;
		e->next = s;

		ListNode *inters = detectCycle(p1);
		if (inters)
			printf("get intersect %d\n", inters->val);
	}

	if (1)
	{
		int a[] = { 2, 2, 3, 4 };
		ListNode *p1 = createList(a, sizeof(a) / sizeof(a[0]));

		ListNode *inters = detectCycle(p1);
		if (inters)
			printf("get intersect %d\n", inters->val);
	}
}

int main()
{
	test_hasCycle();
	test_detectCycle();

	getchar();
}