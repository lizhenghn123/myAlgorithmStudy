// Source : https://oj.leetcode.com/problems/pascals-triangle/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-07

/**********************************************************************************
*
* Given numRows, generate the first numRows of Pascal's triangle.
*
* For example, given numRows = 5,
* Return
*
* [
*      [1],
*     [1,1],
*    [1,2,1],
*   [1,3,3,1],
*  [1,4,6,4,1]
* ]
*
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > vec2d;
	if (numRows <= 0)
		return vec2d;

	vector<int> v;
	v.push_back(1);  // row 1
	vec2d.push_back(v);
	if (numRows == 1)
		return vec2d;

	v.push_back(1);   // row 2
	vec2d.push_back(v);
	if (numRows == 2)
		return vec2d;
	
	for (int row = 3; row <= numRows; ++row)
	{
		vector<int> vec(row);
		vec[0] = vec[row - 1] = 1;
		for (int i = 1; i < row - 1; ++i)
		{
			vec[i] = vec2d[row - 1 - 1][i - 1] + vec2d[row - 1 - 1][i];
		}

		vec2d.push_back(vec);
	}
	return vec2d;
}

vector<int> getRow(int rowIndex) 
{
	vector<int> vec;
	if (rowIndex < 0)
		return vec;

	vec.push_back(1);  // row 1
	if (rowIndex == 0)
		return vec;

	vec.push_back(1);   // row 2
	if (rowIndex == 1)
		return vec;

	vec.resize(rowIndex + 1);
	vector<int> result(rowIndex + 1);
	for (int row = 3; row <= rowIndex + 1; ++row)
	{
		result[0] = result[row - 1] = 1;
		for (int i = 1; i < rowIndex; ++i)
		{
			result[i] = vec[i - 1] + vec[i];
		}

		vec.swap(result);
	}

	return vec;
}

/**********************************************************************************
*
* Given an index k, return the kth row of the Pascal's triangle.
*
* For example, given k = 3,
* Return [1,3,3,1].
*
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
*
**********************************************************************************/
void printTriangle(const vector<vector<int> >& vec2d)
{
	cout << "[" << "\n";
	for (int i = 0; i<vec2d.size(); i++)
	{
		for (int space = (vec2d.size() - i - 1); space >= 0; space--)
		{
			cout << " ";
		}
		cout << "[";

		for (int j = 0; j<vec2d[i].size(); j++)
		{
			cout << vec2d[i][j];
			if (j != vec2d[i].size() - 1)
				cout << ",";
		}
		cout << "]";
		if (i != vec2d.size() - 1)
			cout << ",";
		cout << "\n";
	}
	cout << "]" << "\n";
}

void printVector(const vector<int>& vec)
{
	for (auto i : vec)
		cout << i << ", ";
	cout << "\n-----------------\n";
}

int main()
{
	vector<vector<int> > vec2d = generate(5);
	printTriangle(vec2d);

	vector<int> v1 = getRow(3);
	printVector(v1);

	vector<int> v2 = getRow(5);
	printVector(v2);

	printVector(getRow(0));
	printVector(getRow(1));
	printVector(getRow(2));
	system("pause");
}