#pragma once

#include <stdio.h>
#include <iostream>
#include <sstream>

#ifdef _WIN32
#include "windows.h"
#else
#include <sys/time.h>
#endif

#include "sort/sort_entrance.h"

class process_time
{
public:
	process_time(bool use_usec);
	~process_time();

private:
	bool _usec;

#ifdef _WIN32
	unsigned long start;
	unsigned long end;
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
void print_arr(int arr[], int len);
