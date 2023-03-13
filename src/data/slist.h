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
		: data(0), next(nullptr)
	{}

	~ListNode() {}

public:
	int data;
	ListNode* next;
};

typedef ListNode* LinkList;

void process_slist();


// 初始化链表
ListNode* init_list(int n);

// 打印链表
void dump_list(ListNode* head);


// 单链表翻转
ListNode* reverse(ListNode* head);
ListNode* reverse2(ListNode* head);
// 单链表翻转(自己写一遍)
ListNode* r1(ListNode* head);
ListNode* r2(ListNode* head);