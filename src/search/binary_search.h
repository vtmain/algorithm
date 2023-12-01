#include "search.h"

// 二分查找算法
// 在【有序数组】中查找特定元素
int binary_search(int arr[], int len, int target)
{
    int left = 0;
    int right = len - 1;

    while (left <= right)
    {
        // 中间位置索引
        int mid = left + (right - left) / 2;

        // 看落到左或右哪边
        if (arr[mid] == target)         // 命中，返回
            return mid;
        else if (target < arr[mid])     // 左边
            right = mid - 1;
        else                            // 右边
            left = mid - 1;
    }

    // 没找到。找到的话一定是在 while 循环里返回
    return -1;
}