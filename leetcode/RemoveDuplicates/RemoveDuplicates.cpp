// Source : https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-28
#include <stdio.h>
/**********************************************************************************
*
* Given a sorted array, remove the duplicates in place such that each element appear
* only once and return the new length.
*
* Do not allocate extra space for another array, you must do this in place with constant memory.
*
* For example,
* Given input array A = [1,1,2],
*
* Your function should return length = 2, and A is now [1,2].
*
**********************************************************************************/
int removeDuplicates(int A[], int n)
{
	if (n <= 1)
		return n;

	int idx = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (A[i] != A[i + 1])
			A[++idx] = A[i + 1];
	}

	return idx + 1;
}

/**********************************************************************************
*
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
*
* For example,
* Given sorted array A = [1,1,1,2,2,3],
*
* Your function should return length = 5, and A is now [1,1,2,2,3].
*
**********************************************************************************/
int removeDuplicates_II(int A[], int n)
{
	if (n <= 2)
		return n;

	int idx = 0;
	int count = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (A[i] == A[i + 1])          //相等时，最多只允许有两个重复元素
		{
			count++;
			if (count < 2)
			{
				A[++idx] = A[i + 1];
			}
		}
		else
		{
			count = 0;
			A[++idx] = A[i + 1];
		}
	}

	return idx + 1;
}

void print_array(int a[], int len)
{
	for (int i = 0; i < len; ++i)
		printf("%d, ", a[i]);
	printf("\n---------\n");
}

int main()
{
	{
		int a[] = { 1, 1, 1 };
		int len = removeDuplicates(a, sizeof(a) / sizeof(a[0]));
		print_array(a, len);
	}
	{
		int a[] = { 1, 1, 1, 2, 2, 3 };
		int len = removeDuplicates(a, sizeof(a) / sizeof(a[0]));
		print_array(a, len);
	}
	{
		int a[] = { 1, 1, 1, 2, 2, 3, 3, 3 };
		int len = removeDuplicates(a, sizeof(a) / sizeof(a[0]));
		print_array(a, len);
	}


	{
		int a[] = { 1, 1, 1 };
		int len = removeDuplicates_II(a, sizeof(a) / sizeof(a[0]));
		print_array(a, len);
	}

	{
		int a[] = { 1, 1, 1, 2, 2, 3 };
		int len = removeDuplicates_II(a, sizeof(a) / sizeof(a[0]));
		print_array(a, len);
	}
	{
		int a[] = { 1, 1, 1, 2, 2, 3, 3, 3 };
		int len = removeDuplicates_II(a, sizeof(a) / sizeof(a[0]));
		print_array(a, len);
	}

	getchar();
}