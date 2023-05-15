#include "sort.h"

// STL全局函数，返回 a,b,c 之居中者
template <class T>
inline const T& __median(const T& a, const T& b, const T& c)
{
	if (a < b)
		if (b < c) 		// a < b < c
			return b;
		else if (a < c) // a < c <= b
			return c;
		else 
			return a;
	else if (a < c)
		return a; 		// b <= a < c
	else if (b < c) 	// b < c <= a
		return c;
	else 
		return b;
}

// 找出 2^k <= n 的最大值 k，例如：n=7，得 k=2，n=20，得 k=4，n=8，得 k=3
template <class Size>
inline Size __lg(Size n)
{
	Size k;
	for (k = 0; n > 1; n >> 1) ++k;
	return k;
}

// STL sort 函数
template <class RandomAccessIterator>
inline void sort(RandomAccessIterator first, RandomAccessIterator last)
{
	if (first != last)
	{
		// 先正常排序，内部有条件执行快排或堆排序
		__introsort_loop(first, last, value_type(first), __lg(last - first) * 2);

		// 最后对小序列执行一次插入排序
		__final_insertion_sort(first, last);
	}
}

// 阈值常量 16，超过此值的，认为是长序列，需要尝试用快排做拆分（实际仍要受到递归深度的限制，过深的话会改用堆排序）
const int __stl_threshold = 16;

template <class RandomAccessIterator, class T, class Size>
void __introsort_loop(RandomAccessIterator first, RandomAccessIterator last, T*, Size depth_limit)
{
	while (last - first > __stl_threshold) 	// 只有长度大于16的序列，会进入快排(或堆排序)，否则进不到 while 循环，只能走外层插入排序
	{
		if (depth_limit == 0) 	// 循环至此，depth_limit 已经减为0，说明已达最大递归深度，改用堆排序
		{
			partial_sort(first, last, last); 	// 部分排序，但是传的 middle 值是 last，就成了全序列排序
			return;
		}

		// 递归深度
		--depth_limit;

		// 分割做快排（中值 = 首/中/尾 三者中间值）
		RandomAccessIterator cut = __unguarded_partition(first,
														last,
														T(__median(*first,
																*(first + (last - first)/2),
																*(last - 1)))
														);

		// 对分割后的左右两段，继续递归，决定用哪种排序方式
		// 其中右半段是正常递归，左半段是通过继续走 while 循环的方式来完成递归
		__introsort_loop(cut, last, value_type(first), depth_limit);
		last = cut;
	}
}
