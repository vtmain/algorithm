#pragma once

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#ifdef _WIN32
#include "windows.h"
#else
#include <sys/time.h>
#endif

#include "sort/sort.h"

class process_time
{
public:
	process_time(bool use_usec = false);
	~process_time();

private:
	bool _us; 	// 是否使用微秒计时(true:微秒us false:毫秒ms)

#ifdef _WIN32
	int64_t start;
	int64_t end;
#else
	int64_t start_ms;
	int64_t end_ms;

	int64_t start_us;
	int64_t end_us;

	int64_t _start;
	int64_t _end;
#endif
	
};

void alg_run();
