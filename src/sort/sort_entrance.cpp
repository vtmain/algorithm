#include "sort_entrance.h"
#include "../algorithm.h"
#include <algorithm>

void sort()
{
	// 初始化数组
	int arr[20] = {};
	int len = sizeof(arr) / sizeof(int);
	init_arr(arr, len);

	// 打印初始数组，并开始计时
	std::cout << "arr size: " << len << std::endl;
	print_arr(arr, len);
	process_time pt(true);

	// 选择一种排序方法执行
	select_func(arr, len);

	// 打印排序结果
	print_arr(arr, len);
}

void init_arr(int arr[], int len)
{
	// 顺序填充len个数字
	for (int i = 0; i < len; i++)
		arr[i] = i + 1;

#ifdef _WIN32
	srand(GetTickCount64());
#else
	srand(time(0));
#endif

	// 乱序算法(洗牌算法)
	for (int k = len - 1; k >= 0; k--)
	{
		int n = rand() % (k + 1);
		swap(arr, k, n);
	}
}

void select_func(int arr[], int len)
{
	//bubble(arr, len);
	quick(arr, len);
	//insert(arr, len);
}

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void print_arr(int arr[], int len)
{
	std::ostringstream oss;
	oss << "[";
	for (int i = 0; i < len; i++)
	{
		if (i != 0)
			oss << ", ";
		oss << arr[i];
	}
	oss << "]";
	std::cout << oss.str() << std::endl;
}