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

//������������ĺϲ���ʹ��ֱ�Ӳ���������㷨���趨A�Ѿ�����
//������B�е�Ԫ��������뵽�����A��
void merge(int A[], int m, int B[], int n) 
{
	for (int i = 0; i < n; ++i)
	{
		int j = m + i - 1;   //A���������±�
		int pos = m + i;
		while (j >= 0 && A[j] > B[i])  //�Ӻ���ǰ��λ��
		{
			A[pos] = A[j];
			pos--;
			j--;
		}
		A[pos] = B[i];
	}
}

//�����һ�γɹ����Һ�ͻȻ�뵽��ֱ�Ӳ�����������һ�ξ�δ��һ�����뵽˼·
int main()
{
	const int blen = 5;
	int b[] = { 5, 15, 25, 45, 80 };
	int a[4 + blen] = { 10, 20, 30, 40 };
	merge(a, 4, b, blen);

	printArray(a, sizeof(a) / sizeof(a[0]));

	getchar();
}