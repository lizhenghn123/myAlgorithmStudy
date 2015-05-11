// Source : https://leetcode.com/problems/remove-linked-list-elements/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-11

/**********************************************************************************
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
**********************************************************************************/
#include <stdio.h>
#include <time.h>
#include "../common/single_list.hpp"

int main()
{
	{
		int a[] = { 1, 4, 3, 2, 5, 2 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);
		p = removeElements(p, 2);
		printList(p);
		printf("------------------------\n");
	}
	{
		int a[] = { 1, 1 };
		ListNode *p = createList(a, sizeof(a) / sizeof(a[0]));
		printList(p);
		p = removeElements(p, 1);
		printList(p);
		printf("------------------------\n");
	}
	getchar();
}