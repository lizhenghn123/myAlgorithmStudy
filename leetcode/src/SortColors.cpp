// Source : https://leetcode.com/problems/sort-colors/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-12
/**********************************************************************************
leetcode 75

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
**********************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution75
{
public:
	void sortColors(vector<int>& nums)
	{
		//std::sort(nums.begin(), nums.end());
		QuickSort(nums, 0, nums.size() - 1);
	}

	int Partition(vector<int>& a, int low, int high)
	{
		int pivot = a[low];
		while (low < high)
		{   //先从后往前找一个比pivot小的，再从前往后找一个比pivot大的
			while (low < high && a[high] >= pivot)
				high--;
			a[low] = a[high];

			while (low < high && a[low] <= pivot)
				low++;
			a[high] = a[low];
		}
		a[low] = pivot;
		return low;
	}
	void QuickSort(vector<int>& a, int low, int high)
	{
		if (low < high)
		{
			int pivotloc = Partition(a, low, high);
			QuickSort(a, low, pivotloc - 1);
			QuickSort(a, pivotloc + 1, high);
		}
	}
};

void print(const vector<int>& vec)
{
	for (auto& i : vec)
		cout << i << " ";
	cout << "\n";
}

int main()
{
	vector<int> v1 = { 1, 1, 2, 0, 2, 0, 0, 0, 1, 0, 2, 1 };
	Solution75().sortColors(v1);
	print(v1);

	system("pause");
}
