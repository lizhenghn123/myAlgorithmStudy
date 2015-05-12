// Author : lizhenghn@gmail.com
// Date   : 2014-12-07
#include <iostream>
#include <vector>
using namespace std;

// 从这个排序且旋转过的数组中找到分界线
int getPosOfRatetedSortedArray(int A[], int n)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (A[mid] > A[n - 1])
		{
			if (mid + 1 < n && A[mid + 1] <= A[n - 1])  // A = [3, 1] target = 1
				return mid;
			low = mid + 1;
		}
		else // if (A[mid] < A[n - 1])
		{
			if (mid - 1 < 0 && A[mid - 1] >= A[n - 1]) // fix : mid-1 < 0 ?  A Bug? 
				return mid;
			high = mid - 1;
		}
	}
	return -1;
}

int search(int A[], int low, int high, int target)
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

int search(int A[], int n, int target)
{
	int pos = getPosOfRatetedSortedArray(A, n);

	int indx1 = search(A, 0, pos, target);
	if (indx1 != -1)
		return indx1;
	int indx2 = search(A, pos+1, n-1, target);
	return indx2;
}

/**********************************************************************************
leetcode 33
*
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*
* You are given a target value to search. If found in the array return its index, otherwise return -1.
*
* You may assume no duplicate exists in the array.
*
**********************************************************************************/
void test1()
{
	{
		int a[] = { 3, 1 };
		int len = sizeof(a) / sizeof(a[0]);
		cout << search(a, len, 1) << "\n";
		cout << "--------\n";
	}
	{
		int a[] = { 1 };
		int len = sizeof(a) / sizeof(a[0]);
		cout << search(a, len, 0) << "\n";
		cout << search(a, len, 2) << "\n";
		cout << search(a, len, 9) << "\n";
		cout << "--------\n";
	}
	{
		int a[] = { 4, 5, 6, 7, 0, 1, 2 };
		int len = sizeof(a) / sizeof(a[0]);
		cout << search(a, len, 5) << "\n";
		cout << search(a, len, 2) << "\n";
		cout << search(a, len, 9) << "\n";
		cout << "--------\n";
	}
	{
		int a[] = { 4, 5, 6, 7, 8, 9 };
		int len = sizeof(a) / sizeof(a[0]);
		cout << search(a, len, 5) << "\n";
		cout << search(a, len, 2) << "\n";
		cout << search(a, len, 9) << "\n";
		cout << "--------\n";
	}
}

// https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
/**********************************************************************************
leetcode 81
*
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
*
* Would this affect the run-time complexity? How and why?
*
* Write a function to determine if a given target is in the array.
*
**********************************************************************************/
class Solution81 
{
public:
	bool search(vector<int>& nums, int target)
	{
		int pos = getPosOfRatetedSortedArray(nums);

		int indx1 = search(nums, 0, pos-1, target);
		if (indx1 != -1)
			return true;
		int indx2 = search(nums, pos , nums.size() - 1, target);
		return indx2 != -1;
	}

	// 从这个排序且旋转过的数组中找到分界线
	int getPosOfRatetedSortedArray(vector<int>& nums)  // see #154(FindMinimuminRotatedSortedArrayII)
	{
		size_t start = 0;
		size_t end = nums.size() - 1;
		while (start < end)
		{
			if (nums[end] == nums[start])
			{
				start++;
				continue;
			}
			else if (nums[end] > nums[start])
			{
				break;
			}

			size_t mid = (start + end) / 2;
			if (nums[start] > nums[mid])
				end = mid;
			else
				start = mid + 1;
		}

		return start;
	}

	// 二分法查找
	int search(vector<int>& A, int low, int high, int target)
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
};

void test2()
{
	{
		vector<int> vec = { 1, 3, 1, 1, 1 };
		cout << Solution81().search(vec, 3) << "\n";
		cout << "--------\n";
	}
	{
		vector<int> vec = { 3, 1, 1, 1, 1 };
		cout << Solution81().search(vec, 3) << "\n";
		cout << "--------\n";
	}
	{
		vector<int> vec = { 3, 1};
		cout << Solution81().search(vec, 1) << "\n";
		cout << "--------\n";
	}
}
int main()
{
	test1();
	cout << "######################################\n";
	test2();

	system("pause");
}