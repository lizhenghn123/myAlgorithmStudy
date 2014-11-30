// Source : https://oj.leetcode.com/problems/merge-sorted-array/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
*
* Note:
*   You may assume that A has enough space (size that is greater or equal to m + n)
*   to hold additional elements from B. The number of elements initialized in A and B
*   are m and n respectively.
*
**********************************************************************************/
#include <stdio.h>
#include <assert.h>

void printArray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d\t", a[i]);
	printf("\n");
}

//两个有序数组的合并。使用直接插入排序的算法，设定A已经有序，
//将数组B中的元素逐个插入到有序的A中
void merge(int A[], int m, int B[], int n) 
{
	for (int i = 0; i < n; ++i)
	{
		int j = m + i - 1;   //A数组的最大下标
		int pos = m + i;
		while (j >= 0 && A[j] > B[i])  //从后向前找位置
		{
			A[pos] = A[j];
			pos--;
			j--;
		}
		A[pos] = B[i];
	}
}

//这个题一次成功，幸好突然想到了直接插入排序，再来一次就未必一下子想到思路
int main()
{
	const int blen = 5;
	int b[] = { 5, 15, 25, 45, 80 };
	int a[4 + blen] = { 10, 20, 30, 40 };
	merge(a, 4, b, blen);

	printArray(a, sizeof(a) / sizeof(a[0]));

	getchar();
}