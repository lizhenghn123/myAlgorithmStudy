// Source : https://leetcode.com/problems/rotate-array/
// Author : lizhenghn@gmail.com
// Date   : 2015-05-12
/**********************************************************************************
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
**********************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int>& nums, int start, int end)
{
	int mid = (end - start + 1) / 2 + start;
	for (int i = start; i<mid; ++i)
	{
		int tmp = nums[i];
		nums[i] = nums[end];
		nums[end] = tmp;
		--end;
	}
}

void rotate(vector<int>& nums, int k)
{
	if (k >= nums.size() || k == 0)
		return;
	reverse(nums, 0, k);
	reverse(nums, k + 1, nums.size() - 1);
	reverse(nums, 0, nums.size() - 1);
}

void print(const vector<int>& vec)
{
	for (auto& i : vec)
		cout << i << " ";
	cout << "\n";
}

int main()
{
	{
		vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
		rotate(v, 3);
		print(v);
	}
	{
		vector<int> v = { 1, 2 };
		rotate(v, 1);
		print(v);
	}
	{
		vector<int> v = { 1, 2 };
		rotate(v, 0);
		print(v);
	}
	system("pause");
}

/*
Input:	[1,2], 1
Output:	[1,2]
Expected:	[2,1]


Input:	[1,2], 0
Output:	[2,1]
Expected:	[1,2]
*/