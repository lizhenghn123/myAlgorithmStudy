// Source : https://oj.leetcode.com/problems/search-insert-position/
// Author : lizhenghn@gmail.com
// Date   : 2014-12-05
/**********************************************************************************
*
* Given a sorted array and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
*
* You may assume no duplicates in the array.
*
* Here are few examples.
* [1,3,5,6], 5 �� 2
* [1,3,5,6], 2 �� 1
* [1,3,5,6], 7 �� 4
* [1,3,5,6], 0 �� 0
*
**********************************************************************************/
#include <iostream>
using namespace std;

int searchInsert(int A[], int n, int target)
{
	int low = 0, high = n - 1;
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
	return low;
}

int main()
{
	int arr[] = { 1, 3, 5, 6 };
	const int len = sizeof(arr) / sizeof(arr[0]);

	cout << searchInsert(arr, len, 1) << "\n";
	cout << searchInsert(arr, len, 3) << "\n";
	cout << searchInsert(arr, len, 5) << "\n";
	cout << searchInsert(arr, len, 6) << "\n";

	cout << searchInsert(arr, len, 2) << "\n";
	cout << searchInsert(arr, len, 7) << "\n";
	cout << searchInsert(arr, len, 0) << "\n";
	cout << searchInsert(arr, len, 4) << "\n";

	system("pause");
}