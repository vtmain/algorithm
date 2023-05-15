#include "algorithm.h"
#include "sort/sort.h"
#include "data/slist.h"
#include "data/integer_range.h"
#include "data/binary_tree.h"


process_time::process_time(bool use_usec /*= false*/)
	: _us(use_usec)
{
	// 	DESCRIPTION
	// 		The functions gettimeofdayand settimeofday can get and set the time as
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
	_start = _us ? (val.tv_sec * 1000000 + val.tv_usec) : (val.tv_sec * 1000 + val.tv_usec / 1000);
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
	_end = _us ? (val.tv_sec * 1000000 + val.tv_usec) : (val.tv_sec * 1000 + val.tv_usec / 1000);
//	std::cout << "start: " << _start<< std::endl;
//	std::cout << "  end: " << _end << std::endl;
	std::cout << "process time: " << _end - _start << (_us ? "(us)" : "(ms)") << std::endl;
#endif
}

///////////////////////////////////////////////

typedef void (*CB_FUNC)();

struct menu_item
{
	menu_item(const int& _order, const std::string& _name, CB_FUNC _func)
		: order(_order), name(_name), func(_func)
	{}

	int order;
	std::string name;
	CB_FUNC func;

	bool operator == (const menu_item& other) const
	{
		return (other.order == order);
	}
};

void get_all(std::vector<menu_item>& _vec)
{
	_vec.clear();
	_vec.push_back(menu_item(1, "排序算法", sort));
	_vec.push_back(menu_item(2, "单链表反转", process_slist));
}

void show_menu(const std::vector<menu_item>& _vec)
{
	std::cout << "从下列选择: " << std::endl;
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		const menu_item& item = _vec.at(i);
		std::cout << item.order << " " << item.name << std::endl;
	}
}


void alg_run()
{
	std::vector<menu_item> _vec;
	get_all(_vec);

	show_menu(_vec);

	std::cout << std::endl << "输入序号: ";
	int n = 0;
	std::cin >> n;
	std::cout << std::endl;

	menu_item item(n, "", NULL);
	auto it = std::find(_vec.begin(), _vec.end(), item);
	if (it == _vec.end())
	{
		std::cout << n << " not found" << std::endl;
		return;
	}
	if (!it->func)
	{
		std::cout << n << " found, func empty" << std::endl;
		return;
	}
	it->func();

	//test_data_type_range();
	//test_data_type_byte();

 	//test_search_tree();
}