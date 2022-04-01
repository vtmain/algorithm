#include "sort_entrance.h"
#include "../algorithm.h"
#include <algorithm>

void sort()
{
	int arr[20] = {};
	int len = sizeof(arr) / sizeof(int);

	for (int i = 0; i < len; i++)
		arr[i] = i + 1;

#ifdef _WIN32
	srand(GetTickCount64());
#else
	srand(time(0));
#endif

	for (int k = len - 1; k >= 0; k--)
	{
		int n = rand() % (k + 1);
//		if (k == len - 1)
//			std::cout << "random num: <" << n;
//		else
//			std::cout << ", " << n;

		int tmp = arr[k];
		arr[k] = arr[n];
		arr[n] = tmp;
	}
//	std::cout << ">" << std::endl;

	std::cout << "arr size: " << len << std::endl;
	print_arr(arr, len);
	process_time pt(true);

	////////////////////////////////////////////////

	bubble(arr, len);
	//quick(arr, len);

	////////////////////////////////////////////////

	print_arr(arr, len);
}