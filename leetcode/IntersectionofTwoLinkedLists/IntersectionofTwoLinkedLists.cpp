// Source : https://oj.leetcode.com/problems/intersection-of-two-linked-lists/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-28
#include <iostream>
#include <stdio.h>
#include "../common/single_list.hpp"

ListNode* getMiddleOfList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *fast = head;
	ListNode *slow = head;

	while (fast->next && fast->next->next)   //find list middle
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
	size_t len1 = length(headA);
	size_t len2 = length(headB);

	ListNode *p1 = headA;
	ListNode *p2 = headB;

	if (len1 > len2)
	{
		size_t distance = len1 - len2;
		while (p1 && distance > 0)
		{
			p1 = p1->next;
			--distance;
		}
	}
	else if (len1 < len2)
	{
		size_t distance = len2 - len1;
		while (p2 && distance > 0)
		{
			p2 = p2->next;
			--distance;
		}
	}

	while (p1 && p2)
	{
		if (p1 == p2)
			return p1;
		else
		{
			p1 = p1->next;
			p2 = p2->next;
		}
	}

	return NULL;
}

int main()
{

}