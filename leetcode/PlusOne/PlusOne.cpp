// Source : https://oj.leetcode.com/problems/plus-one/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-25

/**********************************************************************************
*
* Given a non-negative number represented as an array of digits, plus one to the number.
*
* The digits are stored such that the most significant digit is at the head of the list.
*
**********************************************************************************/
#include <stdio.h>
#include <vector>
using namespace std;

//用数组表示的非负整数，求其加1后的结果
vector<int> plusOne(vector<int> &digits)
{
	vector<int> result;
	int plus = 1;

	const int len = static_cast<int>(digits.size());
	for (int i = len - 1; i >= 0; --i)
	{
		int tmp = digits[i] + plus;
		result.insert(result.begin(), tmp % 10);
		plus = tmp / 10;
	}

	if (plus > 0)
		result.insert(result.begin(), plus);

	return result;
}

void printVector(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		printf("%d", vec[i]);
	}
	printf("\n");
}

int main()
{
	{
		vector<int> vec = { 1, 2, 3, 4, 5 };
		vector<int>ret = plusOne(vec);  // 12346
		printVector(ret);
	}
	{
		vector<int> vec = { 9, 9, 9, 9, 9 };
		vector<int> ret = plusOne(vec);  //100000
		printVector(ret);
	}

	system("pause");
}