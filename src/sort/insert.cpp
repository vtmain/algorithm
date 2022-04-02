#include "sort_entrance.h"

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
