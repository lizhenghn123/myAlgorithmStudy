// Source : https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-01

/**********************************************************************************
*
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
*
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*
* Some examples:
*
*   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
*   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*
*
**********************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool isOperator(const string& str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

int getResult(const int& op1, const int& op2, const string& op)
{
	if (op == "+")
		return op1 + op2;
	else if (op == "-")
		return op1 - op2;
	else if (op == "*")
		return op1 * op2;
	else if (op == "/")
		return op1 / op2;
}

//没有异常处理，总是假定待处理的逆波兰表达式是正确的。
int evalRPN(vector<string> &tokens)
{
	stack<int> ss;
	const size_t size = tokens.size();
	for (size_t i = 0; i < size; ++i)
	{
		const string& str = tokens[i];
		if (!isOperator(str))
		{
			ss.push(atoi(str.c_str()));
		}
		else
		{
			int op2 = ss.top();  ss.pop();
			int op1 = ss.top();  ss.pop();
			ss.push(getResult(op1, op2, str));
		}
	}
	return ss.top();
}

int main()
{
	vector<string> v1 = { "2", "1", "+", "3", "*" };
	cout << evalRPN(v1) << "\n";
	vector<string> v2 = { "4", "13", "5", "/", "+" };
	cout << evalRPN(v2) << "\n";

	system("pause");
}