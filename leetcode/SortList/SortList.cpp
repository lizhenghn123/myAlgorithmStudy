#include <iostream>
#include <time.h>
#include "../common/single_list.hpp"

ListNode* sortList_SelectSort(ListNode *head)             //select sort, ok, but sometimes Time Limit Exceeded
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *pivot, *next2;
	ListNode *next = head;
	while (next)
	{
		pivot = next;
		next2 = next->next;
		while (next2)
		{
			if (next2->val < pivot->val)
				pivot = next2;
			next2 = next2->next;
		}

		if (pivot != next && pivot->val != next->val)
		{
			int tmp = pivot->val;
			pivot->val = next->val;
			next->val = tmp;
		}

		next = next->next;
	}
	return head;
}

ListNode* sortList_BubbleSort(ListNode *head)             //bubble sort, ok, but sometimes Time Limit Exceeded
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *pivot, *next2;
	ListNode *next = head;
	bool success = true;
	while (true)
	{
		success = true;
		pivot = next;
		next2 = next->next;
		while (next2)
		{
			if (next2->val < pivot->val)
			{
				int tmp = pivot->val;
				pivot->val = next2->val;
				next2->val = tmp;
				success = false;
			}
			pivot = next2;
			next2 = next2->next;
		}
		//printList(head);
		if (success == true)
			break;
	}
	return head;
}

int main()
{
	if (0)
	{
		int a[] = { 1, 3, 3, 1, 3, 1, 3, 3, 2, 3, 2, 2, 1, 1, 1, 3, 2, 2, 1, 1, 2, 2, 2, 3, 3, 1, 1, 2, 2, 2, 1, 2, 1, 1, 2, 3, 3, 2, 2, 3, 2, 3, 2, 2, 2, 1, 1, 3, 2, 3, 3, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2 };
		int n = sizeof(a) / sizeof(a[0]);
		ListNode *p = createList(a, n);
		printList(p);
		printf("------------------------\n");

		p = sortList_SelectSort(p);    // Time Limit Exceeded
		printList(p);

		freeList(p);
	}
	if (0)
	{
		int a[] = { 8581, 6131, 9495, 2797, 105, 3247, 16943, 16984, 11099, -9031, -2956, -3444, 9150, 11509, -7116, 16806, 7056, -8024, -3161, 19483, -6034, 10318 };
		int n = sizeof(a) / sizeof(a[0]);
		ListNode *p = createList(a, n);
		printList(p);
		printf("------------------------\n");

		p = sortList_BubbleSort(p);    // Time Limit Exceeded
		printList(p);

		freeList(p);
	}

	printf("------------------------\n");
	srand(time(NULL));
	int n = 10;
	int *a = new int[n];
	for (int i = 0; i<n; i++)
		a[i] = rand() % n + 1;

	ListNode *p = createList(a, n);
	delete[] a;
	printList(p);

	p = reverseList(p);
	printList(p);

	//p = sortList(p);
	p = sortList_BubbleSort(p);
	printList(p);
	freeList(p);

	system("pause");
}