#include "sort_entrance.h"
#include "../algorithm.h"

void sort()
{
	int arr[] = { 9, 13, 6, 5, 2, 3, 8, 4, 7 };
	int len = sizeof(arr) / sizeof(int);
	std::cout << "arr size: " << len << std::endl;
	print_arr(arr, len);
	process_time pt(true);

	bubble(arr, len);
	//quick(arr, len);

	print_arr(arr, len);
}