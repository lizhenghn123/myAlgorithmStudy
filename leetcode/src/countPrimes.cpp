// Source : https://leetcode.com/problems/count-primes/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-11

/**********************************************************************************
Description:
Count the number of prime numbers less than a non-negative number, n
**********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <memory>
#include <math.h>
#include <stdio.h>
#include <assert.h>
using namespace std;

// How Many Primes Are There?  https://primes.utm.edu/howmany.html

// 求小于整数n的所有数中素数的个数
int countPrimes(int n)
{
	bool *pb = new bool[n];
	for (int i = 0; i < n; ++i)
		pb[i] = true;    // every one is primer
	pb[0] = pb[1] = false;

	int sqrtN = sqrt(n);
	for (int i = 2; i <= sqrtN; i++)
	{
		if (pb[i] == false)
		{
			continue;
		}
		else
		{
			int p = i * i;  // i + i --> i * i, 减少 p = i * next, next ->[2,i] 的计算
			while (p < n)
			{
				pb[p] = false;
				p += i;
			}
		}
	}

	int count = 0;
	for (int i = 2; i < n; ++i)
	{
		if (pb[i] == true)
			count += 1;
	}
	delete[] pb;

	return count;
}

int main()
{
	cout << countPrimes(2) << "\n";
	cout << countPrimes(10) << "\n";
	cout << countPrimes(1000) << "\n";

	system("pause");
}