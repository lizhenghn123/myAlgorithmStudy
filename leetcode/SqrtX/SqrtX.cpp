// Source : https://oj.leetcode.com/problems/sqrtx/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-07

/**********************************************************************************
*
* Implement int sqrt(int x).
*
* Compute and return the square root of x.
*
**********************************************************************************/

#include <stdio.h>
#include <math.h>

int sqrt(int x)
{
	int low = 0;
	int high = x / 2 + 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		long long num = (long long)mid * mid;
		if (num == x)
			return mid;
		else if (num > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return high;
}

int main()
{
	//printf("%f\n", sqrt(4.0));
	//printf("%f\n", sqrt(167.0));
	printf("%d\n", sqrt(2));
	printf("%d\n", sqrt(4));
	printf("%d\n", sqrt(3));
	getchar();
}