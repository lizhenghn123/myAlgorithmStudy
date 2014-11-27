// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-27
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"


ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
	ListNode dummy(0);
	ListNode *cursor = &dummy;

	int plus = 0;
	while (l1 || l2)
	{
		plus = plus + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
		ListNode *node = new ListNode(plus % 10);
		plus = plus / 10;

		cursor->next = node;
		cursor = node;

		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}

	while (plus)
	{
		ListNode *node = new ListNode(plus % 10);
		plus = plus / 10;
		cursor->next = node;
		cursor = node;
	}

	return dummy.next;
}

int main()
{

}