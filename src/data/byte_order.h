/************************************************************************
*  FileName:	byte_order
*  Description:	字节序
*  Author:		phil
*  Date:		2022-05-25
*  Version:		
************************************************************************/
#pragma once
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

#ifdef _WIN32
    #include <windows.h>
    #pragma comment(lib, "wsock32.lib")

    #define  IS_LITTLE_ENDIAN true		// TO-DO
    #define  IS_BIG_ENDIAN false
#else
	#include <arpa/inet.h>
    #define  IS_LITTLE_ENDIAN (__BYTE_ORDER == __LITTLE_ENDIAN)
    #define  IS_BIG_ENDIAN (__BYTE_ORDER == __BIG_ENDIAN)
#endif // !_WIN32


void dump_byte_order()
{
	union udata
	{
		int n;
		char arr[4];
	};

	udata data;
	data.n = 0x12345678;

	std::cout << "dump_byte_order: 0x" << std::hex << data.n << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << (int)data.arr[i] << "   addr: 0x" << std::hex << ((int*)&data.arr[i]) << std::endl;
		//printf("%x   p:%p \n", data.arr[i], &data.arr[i]);
	}
}

void check_sys_byte_order()
{
	if (IS_BIG_ENDIAN)
	{
		std::cout << "system byte order: big endian" << std::endl;
	}
	else if (IS_LITTLE_ENDIAN)
	{
		std::cout << "system byte order: little endian" << std::endl;
	}
	else
	{
		std::cout << "unknow byte order" << std::endl;
	}
}


// double 字节序转换
double htonl_dbl(double val)
{
	double ret = val;
#if IS_LITTLE_ENDIAN
	int64_t n64 = *((int64_t*)&val);
	int64_t n64b = (((int64_t)htonl((unsigned long)n64)) << 32 | htonl((unsigned long)(n64 >> 32)));
	ret = *((double*)&n64b);
#endif
	return ret;
}

//////////////////////////////////////////////////////////////////////////////////

struct int64tonet
{
	union
	{
		int64_t w_;
		int r_[2];
	}w, r;

	int64tonet(int64_t i)
	{
		w.w_ = i;
		r.r_[0] = htonl(w.r_[1]);
		r.r_[1] = htonl(w.r_[0]);
	}

	int64_t operator() ()
	{
		return r.w_;
	}
};

#define  INT64_TO_NET(val)    ((int64_t)( \
    (((int64_t)(val) & 0x00000000000000FF) << 56) | \
    (((int64_t)(val) & 0x000000000000FF00) << 40) | \
    (((int64_t)(val) & 0x0000000000FF0000) << 24) | \
    (((int64_t)(val) & 0x00000000FF000000) <<  8) | \
    (((int64_t)(val) & 0x000000FF00000000) >>  8) | \
    (((int64_t)(val) & 0x0000FF0000000000) >> 24) | \
    (((int64_t)(val) & 0x00FF000000000000) >> 40) | \
    (((int64_t)(val) & 0xFF00000000000000) >> 56)))

void int64_to_net()
{
	int64_t i = 0x1122334455667788;
	int64tonet j(i);
	int64_t m = j();
	int64_t n = INT64_TO_NET(i);
	std::cout << "i: 0x" << std::hex << i << ", to big endian: 0x" << std::hex << m << std::endl;
	std::cout << "i: 0x" << std::hex << i << ", to big endian: 0x" << std::hex << n << std::endl;
}