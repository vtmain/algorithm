/************************************************************************
*  FileName:	integer_range
*  Description:	整数范围
*  Author:		phil
*  Date:		2022-04-12
*  Version:		
************************************************************************/
#pragma once
#include <limits>
#include <iostream>
#include <climits>
#include <bitset>

template<typename T>
void binary_output(T t)
{
	T min_val = std::numeric_limits<T>::min();
	T max_val = std::numeric_limits<T>::max();
	const char* name = typeid(t).name();

	std::bitset<8 * sizeof(T)> bs_min(min_val);
	std::cout << "[type:" << name << "] min: " << min_val << "(" << bs_min << ")" << " [binary len:" << bs_min.size() << "]" << std::endl;

	std::bitset<8 * sizeof(T)> bs_max(max_val);
	std::cout << "[type:" << name << "] max: " << max_val << "(" << bs_max << ")" << " [binary len:" << bs_max.size() << "]" << std::endl;
}

void test_integer()
{
	char a = '5';	// SCHAR_MIN;
	short b = 5;	// SHRT_MAX;
	int c = 5;		// INT_MAX;
	long d = 5;		// ((long)INT_MAX) + 1;
	int64_t e = 5;	// ((int64_t)INT_MAX) + 1;

	binary_output(a);
	binary_output(b);
	binary_output(c);
	binary_output(d);
	binary_output(e);

	int64_t bp = (int64_t)INT_MAX + 1;
	int64_t bn = (int64_t)INT_MIN - 1;
	std::cout << bp << ((bp > INT_MAX) ? " > " : " < ") << "INT_MAX(" << INT_MAX << ")" << std::endl;
	std::cout << bn << ((bn > INT_MIN) ? " > " : " < ") << "INT_MIN(" << INT_MIN << ")" << std::endl;

	int m = 1;
	std::cout << (m << 16) << std::endl;
}

