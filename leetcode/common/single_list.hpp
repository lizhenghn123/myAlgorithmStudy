#ifndef SINGLE_LIST_HPP
#define SINGLE_LIST_HPP

// singly-linked list node
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int a[], int n)
{
	ListNode *head = NULL, *p = NULL;
	for (int i = 0; i < n; i++)
	{
		if (head == NULL)
		{
			head = p = new ListNode(a[i]);
		}
		else
		{
			p->next = new ListNode(a[i]);
			p = p->next;
		}
	}
	return head;
}

void freeList(ListNode *head)
{
	ListNode *p = head;
	ListNode *q = head;
	while (p)
	{
		q = q->next;
		delete p;
		p = q;
	}
	head = NULL;
}

size_t length(ListNode *head)
{
	size_t len = 0;
	ListNode *p = head;
	while (p)
	{
		++len;
		p = p->next;
	}
	return len;
}

ListNode* removeElements(ListNode* head, int val)
{
	ListNode dummy(0);
	dummy.next = head;

	ListNode *d = &dummy;
	ListNode *p = head;

	while (p)
	{
		while (p && p->val == val)
		{
			p = p->next;
		}
		d->next = p;
		d = d->next;
		p = p ? p->next : p;

	}

	return dummy.next;
}

ListNode* reverseList(ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *newhead = NULL;
	ListNode *next;
	while (head)
	{
		next = head->next;
		head->next = newhead;
		newhead = head;
		head = next;
	}
	return newhead;
}

void printList(ListNode* head)
{
	ListNode *p = head;

	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
}

#endif  /* SINGLE_LIST_HPP */