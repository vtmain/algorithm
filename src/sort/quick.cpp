#include "sort.h"

void partition(int arr[], int _l, int _r)
{
	int left = _l;
	int right = _r;
	if (left <= right)
	{
		// ������ĵ�һ��Ԫ����Ϊ��׼
		int tmp = arr[left];

		// ���ҽ���ɨ��
		while (left != right)
		{
			// ��������ɨ�裬����������С������
			while (left < right && tmp <= arr[right])
				right--;

			// С����������ǰleftָ��λ��
			arr[left] = arr[right];

			// ͬʱleft������һλ����Ϊ��ʱleftָ��λ�øոձ�������䣬û�б�Ҫ�ٱȽ�һ��
			if (left < right)
				left++;

			//////////////////////////////////////////////

			// ��������ɨ�裬С����������������
			while (left < right && arr[left] <= tmp)
				left++;

			// ������������ǰrightָ��λ��
			arr[right] = arr[left];

			// ͬʱright������һλ��ԭ��ͬ�ϣ�rightָ��λ�øոձ�������䣬�´���Ҫ�л��ش��ұ�ɨ����
			if (left < right)
				right--;
		}

		// ����ɨ��ֱ��left��right��ȣ�������Ȼ������
		arr[left] = tmp;

		// ��ʱleft��right��ͬ���ڵ�λ�ã���tmp��Ϊ�ֽ��ߣ���arr�ֳ����������֣�tmp���������ҷֱ�ݹ��ظ��������̼���
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

void quick(int arr[], int len)
{
	//partition(arr, 0, len - 1);
	pa(arr, 0, len - 1);
}