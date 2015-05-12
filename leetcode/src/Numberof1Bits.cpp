// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-12
/**********************************************************************************
leetcode 191

Write a function that takes an unsigned integer and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ¡¯11' has binary representation 00000000000000000000000000001011, so the function should return 3.
**********************************************************************************/
#include <iostream>
#include <inttypes.h>s
#include <vector>
using namespace std;

int hammingWeight(uint32_t n)
{
	int count = 0;
	while (n)
	{
		count += n & 1;
		n = n >> 1;
	}
	return count;
}

void print(const vector<int>& vec)
{
	for (auto& i : vec)
		cout << i << " ";
	cout << "\n";
}

int main()
{
	cout << hammingWeight(1) << "\n";
	cout << hammingWeight(5) << "\n";
	cout << hammingWeight(11) << "\n";
	system("pause");
}
