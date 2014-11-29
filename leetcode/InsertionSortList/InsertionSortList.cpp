// Source : https://oj.leetcode.com/problems/insertion-sort-list/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-29

/**********************************************************************************
*
* Sort a linked list using insertion sort.
*
**********************************************************************************/

#include <iostream>
#include <stdio.h>
#include <time.h>
#include "../common/single_list.hpp"

//链表排序，直接插入法
ListNode* insertionSortList(ListNode *head)
{
	if (head == NULL)
		return NULL;

	ListNode dummy(0);
	dummy.next = head;

	ListNode *p = head->next;
	head->next = NULL;
	while (p)
	{
		ListNode *cursor = dummy.next;
		ListNode *cursor_prev = &dummy;
		while (cursor)
		{
			if (cursor->val > p->val)
			{
				break;
			}
			else
			{
				cursor_prev = cursor;
				cursor = cursor->next;
			}
		}

		ListNode *p_next = p->next;
		cursor_prev->next = p;
		p->next = cursor;

		p = p_next;
	}

	return dummy.next;
}

void test_InsertionSortList()
{
	{
		int a[] = { 1 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);
		printList(insertionSortList(p));
		printf("------------------------\n");
	}
	srand(time(NULL));
	const static int size = 5;
	int arr[size];
	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 100;
	ListNode *head = createList(arr, size);
	printList(head);

	ListNode *p = insertionSortList(head);
	printList(p);
}

int main()
{
	test_InsertionSortList();

	getchar();
}