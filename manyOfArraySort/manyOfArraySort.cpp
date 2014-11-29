#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
using namespace std;

void SelectSort(int a[], int n);            //简单选择排序
void BubbleSort(int a[], int n);            //冒泡排序
void InsertSort(int a[], int n);            //直接插入排序
void BiInsertSort(int a[], int n);          //折半插入排序
void QuickSort(int a[], int low, int high); //快速排序
void ShellSort(int a[], int n);             //希尔排序
void ExchangeSort(int a[], int n);          //奇偶交换排序
void CountSort(int a[], int n);             //计数法排序
void HeapSort(int a[], int n);              //堆排序

void swap(int&a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << "\n";
}

int main()
{
	srand(time(NULL));

	const int size = 10;
	int arr[size];

	if (0)
	{
		cout << "-----------SelectSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		SelectSort(arr, size);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------BubbleSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		BubbleSort(arr, size);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------InsertSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		InsertSort(arr, size);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------BiInsertSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		BiInsertSort(arr, size);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------QuickSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		QuickSort(arr, 0, size-1);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------ShellSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		ShellSort(arr, size);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------ExchangeSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		ExchangeSort(arr, size);
		printArray(arr, size);
	}
	if (0)
	{
		cout << "-----------CountSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		CountSort(arr, size);
		printArray(arr, size);
	}
	if (1)
	{
		cout << "-----------CountSort-----------\n";
		for (int i = 0; i < size; ++i)
			arr[i] = rand() % 100;
		printArray(arr, size);
		HeapSort(arr, size);
		printArray(arr, size);
	}
	system("pause");
}


//********************************************************
void SelectSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

//********************************************************
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)            // n-1 遍
	{
		for (int j = 0; j < n -1 - i; j++)     //前后两两比较
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j+1]);
			}
		}
	}
}

//********************************************************
void InsertSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])
		{
			int pivot = a[i]; 
			a[i] = a[i - 1];
			int j;
			for (j = i - 2; pivot < a[j]; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = pivot;
		}
	}
}

//********************************************************
void BiInsertSort(int a[], int n)
{
	int low, high, mid;
	for (int i = 1; i < n; i++)
	{
		int pivot = a[i];
		low = 0; high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] > pivot)
				high = mid - 1;
			else 
				low = mid + 1;
		}
		for (int j = i - 1; j >= high + 1; j--)
			a[j + 1] = a[j];
		a[high + 1] = pivot;
	}
}

//********************************************************
int Partition(int a[], int low, int high)
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
void QuickSort(int a[], int low, int high)
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(a, low, high);
		QuickSort(a, low, pivotloc - 1);
		QuickSort(a, pivotloc + 1, high);
	}
}

//********************************************************
void ShellInsert(int a[], int n, int jump)
{
	bool flag = 0;
	while (flag == 0)
	{
		flag = 1;
		for (int i = 0; i < n - jump; i++)
		{
			if (a[i] > a[i + jump])
			{
				flag = 0;
				swap(a[i], a[i + jump]);
			}
		}
	}
}
void ShellSort(int a[], int n)
{
	vector<int> t;
	int jump = n / 2;
	while (jump)
	{
		t.push_back(jump);
		jump = jump / 2;
	}
	for (int i = 0; i<t.size(); i++)
		ShellInsert(a, n, t[i]);
}

//********************************************************
void ExchangeSort(int a[], int n)
{
	bool flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < n - 1; i += 2)
		{
			if (a[i] > a[i + 1])
			{
				flag = 1;
				swap(a[i], a[i + 1]);
			}
		}

		for (int i = 1; i < n - 1; i += 2)
		{
			if (a[i] > a[i + 1])
			{
				flag = 1;
				swap(a[i], a[i + 1]);
			}
		}
	}
}

//********************************************************
void CountSort(int a[], int n)
{
#define N 100

	int b[N], c[N];
	for (int i = 0; i < n; ++i)
		b[i] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (a[i] > a[j])
				b[i]++;
		}
	}

	for (int i = 0; i < n; ++i)
		c[b[i]] = a[i];

	for (int i = 0; i < n; ++i)
		a[i] = c[i];
}

//********************************************************
//堆筛选函数, 使H[start~end]成为一个大顶堆
//已知a[start~end]中除了start之外均满足堆的定义
void HeapAdjust(int a[], int start, int end)
{
	int temp = a[start];

	for (int i = 2 * start + 1; i <= end; i *= 2)
	{
		//因为假设根结点的序号为0而不是1，所以i结点左孩子和右孩子分别为2i+1和2i+2
		if (i<end && a[i]<a[i + 1])//左右孩子的比较
		{
			++i;  //i为较大的记录的下标
		}

		if (temp > a[i])//左右孩子中获胜者与父亲的比较
		{
			break;
		}

		//将孩子结点上位，则以孩子结点的位置进行下一轮的筛选
		a[start] = a[i];
		start = i;

	}

	a[start] = temp; //插入最开始不和谐的元素
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2; i >= 0; --i)   //建立大顶堆
	{
		HeapAdjust(a, i, n);
	}

	for (int i = n - 1; i > 0; --i)    //进行排序
	{
		swap(a[0], a[i]);              //最后一个元素和第一元素进行交换

		HeapAdjust(a, 0, i - 1);       //然后将剩下的无序元素继续调整为大顶堆
	}

}