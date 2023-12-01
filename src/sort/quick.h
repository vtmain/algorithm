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
			// 没有必要再比较一次，指的是：若没有此处的 left++，那么下面切换到从左往右扫描时，left 位置刚换过来的小数，没必要再一次参与比较
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

			// 没有跳过 left 位置，在下面 while 循环中，第一次与 tmp 比较的还是这个刚换过来的大数值

			while (left < right && arr[left] <= tmp)
			{
				left++;
			}
			arr[right] = arr[left];

			// 没有跳过 right 位置，同理
		}

		arr[left] = tmp;
		pa(arr, _l, left - 1);
		pa(arr, right + 1, _r);
	}
}

void pa_20231201(int arr[], int _l, int _r)
{
	// 定义游标，因为 _l 和 _r 不能被修改
	int left = _l;
	int right = _r;

	// 确定需要比较的区间，若是无效区间(left > right)则无意义，不需要比较
	if (left <= right)
	{
		int tmp = arr[left]; 	// 选定基准值，不一定非要用数组第一个值，只是写起来方便

		// 左右游标碰头，就结束比较
		while (left != right)
		{
			// 从右往左
			while (left < right && tmp <= arr[right])
				right--;

			// 跳出上面的 while 时，说明上一轮 right-- 之后当前位置的值小于 tmp，交换之
			// 或者 left 和 right 相遇了，那交换一下也无妨
			arr[left] = arr[right];

			// 顺手跳过吧，提高下效率
			if (left < right)
				left++;

			// 从左往右，原理相同，防止相遇即可
			while (left < right && arr[left <= tmp])
				left++;

			// 此时的 arr[right] 位置保留的只是个废弃值（重复值），能够直接被新的满足条件的 arr[left] 覆盖
			// 因为上一步从右往左时，该 right 位置的值实际已经被转移到 left 了
			arr[right] = arr[left];

			if (left < right)
				right--;
		}

		// 跳出到这里，说明 left 与 right 相遇了，本区间（_l ~ _r）排序结束，下面要继续对左右两部分递归
		// 相遇，说明左右两部分以 tmp 为基准，已经区分开大小了，然后把 tmp 放在这个位置就可以了
		// 无所谓 left 或 right，二者现在相等
		arr[left] = tmp;

		// 递归左右两部分
		// 重新定义个变量 mid，代表 tmp 所在的中间数位置，与 left 和 right 值相等，用 mid 好理解些
		int mid = left;
		pa_20231201(arr, _l, mid - 1);
		pa_20231201(arr, mid + 1, _r);
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