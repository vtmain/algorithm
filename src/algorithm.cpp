#include "algorithm.h"
#include "sort/sort.h"
#include "data/slist.h"
#include "data/integer_range.h"
#include "data/binary_tree.h"


process_time::process_time(bool use_usec)
	: _usec(use_usec)
{
	// 	DESCRIPTION
	// 		The functions gettimeofdayand settimeofday can getand set the time as
	// 		well as a timezone.The tv argument is a timeval struct, as specified
	// 		in <sys / time.h> :
	// 
	// 	struct timeval {
	// 		time_t			tv_sec;     /* seconds */
	// 		suseconds_t		tv_usec;	/* microseconds */   // 微秒 10^-6
	// 	};
	// 
	// 毫秒(millisecond)需要从tv_usec计算得来

#ifdef _WIN32
	start = GetTickCount64();
	end = 0;
#else
	timeval val;
	gettimeofday(&val , NULL);
	_start = _usec ? (val.tv_sec * 1000000 + val.tv_usec) : (val.tv_sec * 1000 + val.tv_usec / 1000);
	_end = 0;
#endif
}


process_time::~process_time()
{
#ifdef _WIN32
	end = GetTickCount64();
//	std::cout << "start: " << start << std::endl;
//	std::cout << "end: " << end << std::endl;
	std::cout << "process time: " << end - start << "(ms)" << std::endl;
#else
	timeval val;
	gettimeofday(&val, NULL);
	_end = _usec ? (val.tv_sec * 1000000 + val.tv_usec) : (val.tv_sec * 1000 + val.tv_usec / 1000);
//	std::cout << "start: " << _start<< std::endl;
//	std::cout << "  end: " << _end << std::endl;
	std::cout << "process time: " << _end - _start << (_usec ? "(us)" : "(ms)") << std::endl;
#endif
}

///////////////////////////////////////////////


void alg_run()
{
	//sort();

	//process_slist();

	//test_data_type_range();
	//test_data_type_byte();

 	test_search_tree();
}