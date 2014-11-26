// Source : https://oj.leetcode.com/problems/maximum-subarray/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-25

/**********************************************************************************
*
* Find the contiguous subarray within an array (containing at least one number)
* which has the largest sum.
*
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*
* More practice:
*
* If you have figured out the O(n) solution, try coding another solution using
* the divide and conquer approach, which is more subtle.
*
*
**********************************************************************************/
#include <stdio.h>
#include <assert.h>

//最长连续子序列的最大和，动态规划
int maximumSubarray(int arr[], int n)
{
	int sum = arr[0], b = 0;
	for (int i = 0; i < n; i++)
	{
		if (b > 0)
			b += arr[i];
		else
			b = arr[i];
		if (b > sum)
			sum = b;
	}
	return sum;
}

int main()
{
	{
		int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		printf("get %d\n", maximumSubarray(a, sizeof(a) / sizeof(a[0])));
	}
	{
		int a[] = { -1 };
		printf("get %d\n", maximumSubarray(a, sizeof(a) / sizeof(a[0])));
	}
	{
		int a[] = { -100, -2, -5, -10, -9 };
		printf("get %d\n", maximumSubarray(a, sizeof(a) / sizeof(a[0])));
	}
	getchar();
}