// Source : https://oj.leetcode.com/problems/search-for-a-range/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-05
/**********************************************************************************
*
* Given a sorted array of integers, find the starting and ending position of a given target value.
*
* Your algorithm's runtime complexity must be in the order of O(log n).
*
* If the target is not found in the array, return [-1, -1].
*
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
*
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int A[], int low, int high, int target)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (A[mid] == target)
			return mid;
		else if (A[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

vector<int> searchRange(int A[], int n, int target)
{
	int indx = binarySearch(A, 0, n - 1, target);
	if (indx == -1)
	{
		static vector<int> v = { -1, -1 };
		return v;
	}

	int lowpos = indx; 
	if (lowpos > 0)
	{
		int pos = binarySearch(A, 0, lowpos - 1, target);
		while (pos != -1)
		{
			lowpos = pos;
			pos = binarySearch(A, 0, lowpos - 1, target);
		}
	}

	int highpos = indx;
	if (highpos < n - 1)   // "highpos < n - 2" is ok
	{
		int pos = binarySearch(A, highpos + 1, n - 1, target);
		while (pos != -1)
		{
			highpos = pos;
			pos = binarySearch(A, highpos + 1, n - 1, target);
		}
	}

	vector<int> v = { lowpos, highpos };
	return v;
}

void printVector(const vector<int>& vec)
{
	for (auto i : vec)
		cout << i << "\t";
	cout << "\n";
}

int main()
{
	{
		int arr[] = { 5, 7, 7, 8, 8, 10 };
		const int len = sizeof(arr) / sizeof(arr[0]);

		printVector(searchRange(arr, len, 8));
		printVector(searchRange(arr, len, 7));
		printVector(searchRange(arr, len, 5));
		printVector(searchRange(arr, len, 6));
	}


	{
		int arr[] = { 5, 5, 7, 7, 7, 8, 8, 10, 10, 10 };
		const int len = sizeof(arr) / sizeof(arr[0]);

		printVector(searchRange(arr, len, 7));
		printVector(searchRange(arr, len, 5));
		printVector(searchRange(arr, len, 10));
	}
	system("pause");
}