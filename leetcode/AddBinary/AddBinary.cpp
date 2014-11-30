// Source : https://oj.leetcode.com/problems/add-binary/
// Author : lizhenghn@gmail.com
// Date   : 2014-11-30

/**********************************************************************************
*
* Given two binary strings, return their sum (also a binary string).
*
* For example,
* a = "11"
* b = "1"
* Return "100".
*
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int addBinaryChar(char a, char b, char c)
{
	return a - '0' + b - '0' + c - '0';
}

//做虽做了，可真丑陋
string addBinary(string a, string b)
{
	if (a.empty())
		return b;
	else if (a.empty())
		return a;

	int alen = a.size();
	int blen = b.size();
	string result;

	char plus = '0';
	for (int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; --i, --j)
	{
		int r = addBinaryChar((i < alen && i >= 0) ? a[i] : '0', (j < blen && j >= 0) ? b[j] : '0', plus);
		if (r == 3)  // 3 == '1' + '1' + '1'
		{
			result.insert(result.begin(), '1');
			plus = '1';
		}
		else if (r == 2) // 2 = '1' + '1'
		{
			result.insert(result.begin(), '0');
			plus = '1';
		}
		else if (r == 1) // 1 = '1' 
		{
			result.insert(result.begin(), '1');
			plus = '0';
		}
		else
		{
			result.insert(result.begin(), '0');
			plus = '0';
		}
	}
	
	if (plus != '0')
		result.insert(result.begin(), plus);

	result.shrink_to_fit();
	return result;
}

string addBinary2(string a, string b)
{
	if (a.empty())
		return b;
	else if (a.empty())
		return a;

	int alen = a.size();
	int blen = b.size();
	string result;
	result.resize(alen > blen ? alen + 1 : blen + 1);
	int idx = result.size() - 1;

	char plus = '0';
	for (int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; --i, --j)
	{
		int r = addBinaryChar((i < alen && i >= 0) ? a[i] : '0', (j < blen && j >= 0) ? b[j] : '0', plus);
		if (r == 3)  // 3 == '1' + '1' + '1'
		{
			result[idx--] = '1';
			plus = '1';
		}
		else if (r == 2) // 2 = '1' + '1'
		{
			result[idx--] = '0';
			plus = '1';
		}
		else if (r == 1) // 1 = '1' 
		{
			result[idx--] = '1';
			plus = '0';
		}
		else
		{
			result[idx--] = '0';
			plus = '0';
		}
	}

	if (plus != '0')
		result[idx] = plus;

	result.shrink_to_fit();
	return result;
}
int main()
{
	string a = "11";
	string b = "1";
	cout << addBinary(a, b) << "\n";
	cout << addBinary("1", "11") << "\n";
	cout << addBinary("1111", "11") << "\n";
	cout << addBinary("1011", "11") << "\n";
	cout << addBinary("101", "0") << "\n";
	getchar();
}