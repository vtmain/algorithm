#include "sort.h"

void insert(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int curr = arr[i];
		int prev_index = i - 1;

		while (prev_index >= 0 && arr[prev_index] > curr)
		{
			arr[prev_index + 1] = arr[prev_index];
			prev_index--;
		}

		arr[prev_index + 1] = curr;
	}
}

void insert_20231201(int arr[], int len)
{
	// 3  7  5  4  1  2
	// 3  5  7  4  1  2
	// 3  4  5  7  1  2
	for (int i = 0; i < len; ++i)
	{
		int val = arr[i];
		int left_index = i - 1;

		while (left_index >= 0 && arr[left_index] > val)
		{
			arr[left_index + 1] = arr[left_index];
			left_index--;
		}

		arr[left_index + 1] = val;
	}
}
