#include "sort.h"
#include <vector>

void partition(int arr[], int _l, int _r)
{
	int left = _l;
	int right = _r;
	if (left <= right)
	{
		// 待排序的第一个元素作为基准
		int tmp = arr[left];

		// 左右交替扫描
		while (left != right)
		{
			// 从右往左扫描，大数不动，小数跳出
			while (left < right && tmp <= arr[right])
				right--;

			// 小数左移至当前left指向位置
			arr[left] = arr[right];

			// 同时left向右移一位，因为此时left指向位置刚刚被从右侧移过来的小数填充，没有必要再比较一次
			if (left < right)
				left++;

			//////////////////////////////////////////////

			// 从左往右扫描，小数不动，大数跳出
			while (left < right && arr[left] <= tmp)
				left++;

			// 大数右移至当前right指向位置
			arr[right] = arr[left];

			// 同时right向左移一位，原因同上，right指向位置刚刚被从左侧移过来的大数填充，下次又要切换回从右边扫描了
			if (left < right)
				right--;
		}

		// 交替扫描直至left与right相等，跳出，然后到这里
		arr[left] = tmp;

		// 此时left与right共同所在的位置，即tmp作为分界线，将arr分成左右两部分，tmp不动，左右分别递归重复上述过程即可
		partition(arr, _l, left - 1);
		partition(arr, right + 1, _r);
	}
}

void pa(int arr[], int _l, int _r)
{
	int left = _l;
	int right = _r;
	if (left <= right)
	{
		int tmp = arr[left];
		while (left != right)
		{
			// <-
			while (left < right && arr[right] >= tmp)
			{
				right--;
			}
			arr[left] = arr[right];

			while (left < right && arr[left] <= tmp)
			{
				left++;
			}
			arr[right] = arr[left];
		}

		arr[left] = tmp;
		pa(arr, _l, left - 1);
		pa(arr, right + 1, _r);
	}
}

void partion_it(std::vector<int>& _vec)
{
	
}

void quick(int arr[], int len)
{
	//partition(arr, 0, len - 1);
	pa(arr, 0, len - 1);
}