/************************************************************************
*  FileName:	slist
*  Description:	单链表
*  Author:		phil
*  Date:		2022-04-02
*  Version:		
************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <map>

class ListNode
{
public:
	ListNode()
		: data(""), next(nullptr)
	{}

	~ListNode() {}

public:
	std::string data;
	ListNode* next;
};

typedef ListNode* LinkList;
