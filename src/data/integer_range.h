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
#include <cfloat>
#include "byte_order.h"

#define IS_INT32_VAL(x) (INT_MIN <= (x) && (x) <= INT_MAX)

template<typename T>
void binary_output(T t)
{
	T min_val = (std::numeric_limits<T>::min)();
	T max_val = (std::numeric_limits<T>::max)();
	const char* name = typeid(t).name();

	// linux环境，name只输出单字符，比如int输出"i"，用"./alg | c++filt -t"可以完整输出名称"int"
	std::bitset<8 * sizeof(T)> bs_min(*((uint64_t*)&min_val));
	std::cout << "[type:" << name << "] min: " << min_val << "(" << bs_min << ")" << " [binary len:" << bs_min.size() << "]" << std::endl;

	std::bitset<8 * sizeof(T)> bs_max(*((uint64_t*)&max_val));
	std::cout << "[type:" << name << "] max: " << max_val << "(" << bs_max << ")" << " [binary len:" << bs_max.size() << "]" << std::endl << std::endl;
}

void test_integer()
{
	char a = '5';		// SCHAR_MIN;
	short b = 5;		// SHRT_MAX;
	int c = 5;			// INT_MAX;
	long d = 5;			// ((long)INT_MAX) + 1;
	int64_t e = 5;		// ((int64_t)INT_MAX) + 1;
	float f = 5.0;		// FLT_MAX
	double dbl = 5.0;	// DBL_MAX;

	binary_output(a);
	binary_output(b);
	binary_output(c);
	binary_output(d);
	binary_output(e);
	binary_output(f);
	binary_output(dbl);

	int64_t bp = (int64_t)INT_MAX + 1;
	int64_t bn = (int64_t)INT_MIN - 1;
	std::cout << bp << ((bp > INT_MAX) ? " > " : " < ") << "INT_MAX(" << INT_MAX << ")" << std::endl;
	std::cout << bn << ((bn > INT_MIN) ? " > " : " < ") << "INT_MIN(" << INT_MIN << ")" << std::endl;

	int m = 1;
	std::bitset<8 * sizeof(int)> bsm(m);
	std::cout << m << std::endl;
	std::cout << bsm << std::endl;

	int n = m << 16;
	std::bitset<8 * sizeof(int)> bsn(n);
	std::cout << (n) << std::endl;
	std::cout << bsn << std::endl;

	int64_t j = ((int64_t)INT_MAX);
	int64_t k = ((int64_t)INT_MAX) + 1;
	std::cout << "j: " << j << ", is INT_32: " << std::boolalpha << IS_INT32_VAL(j) << std::endl;
	std::cout << "k: " << k << ", is INT_32: " << std::boolalpha << IS_INT32_VAL(k) << std::endl;
}

void test_range()
{
	// test value
	int n = 1024;	// 2^10 [0100 0000 0000]
	int sizeofint = sizeof(int);	// 4 bytes
	std::cout << "sizeof(int) = " << sizeofint << std::endl;
	std::bitset<8 * sizeof(int)> bsn(n);
	std::cout << "n: " << n << " [" << bsn << "]" << std::endl << std::endl;

	// int64_t (long long)
	int64_t n64 = LLONG_MAX;	// 922 3372 0368 5477 5807
	int sizeofint64 = sizeof(int64_t);	// 8 bytes
	std::cout << "sizeof(int64_t) = " << sizeofint64 << std::endl;
	std::bitset<8 * sizeof(int64_t)> bsn64(n64);
	std::cout << "n64: " << n64 << " [" << bsn64 << "]" << std::endl << std::endl;
	/*
	* output:
	* 
	* [win11 x64]
	* sizeof(int64_t) = 8
	* n64: 9223372036854775807 [0111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111]
	* 请按任意键继续. . .
	* 
	* [ubuntu]
	* sizeof(int64_t) = 8
	* n64: 9223372036854775807 [0111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111]
	* 
	*/

	// double
	double d1 = DBL_MAX;
	int64_t d1_n64 = *((int64_t*)&d1);	// 不是准确的数据类型转换，只是为了观察字节序
#ifdef _WIN32
	double* pd1_little_endian = &d1;	// vs 断点观察
	double d2 = htonl_dbl(d1);			// 不是准确的数据类型转换，只是为了观察字节序
	double* pd2_big_endian = &d2;		// vs 断点观察
#endif
	// little-endian: ff ff ff ff ff ff ef 7f
	//    big-endian: 7f ef ff ff ff ff ff ff 
	//        binary: 0111 1111 1110 1111 ...
	//
	//                0           111 1111 1110      1111 ...
	//               1 bit            11 bit          52 bit
	//           符号位(0正1负)      指数部分        尾数部分
	int sizeofdouble = sizeof(double);	// 8 bytes
	std::cout << "sizeof(double) = " << sizeofdouble << std::endl;
	std::bitset<8 * sizeof(double)> bsd1(d1_n64);
	std::cout << "d1: " << d1 << " [" << bsd1 << "]" << std::endl << std::endl;
	/*
	* output:
	* 
	* [win11 x64]
	* sizeof(double) = 8
	* d1: 1.79769e+308[0111 1111  1110 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111]
	* 请按任意键继续. . .
	* 
	* [ubuntu]
	* sizeof(double) = 8
	* d1: 1.79769e+308[0111 1111  1110 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111  1111 1111]
	* 
	*/

	dump_byte_order();
	check_sys_byte_order();
	int64_to_net();
}

