#include "algorithm.h"

void bubble_sort()
{
	int arr[] = { 9, 13, 6, 5, 2, 3, 8, 4, 7 };
	int len = sizeof(arr) / sizeof(int);
	std::cout << "arr size: " << len << std::endl;
	print_arr(arr, len);
	process_time pt(true);

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}


	print_arr(arr, len);
}