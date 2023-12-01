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

// 算法入口
void process_slist();


// 创建链表
ListNode* create_list_node(int val);
ListNode* create_list(int arr[], int len);

// 打印链表
void dump_list(ListNode* head, char* txt = NULL);


// 单链表翻转
void reverse();
ListNode* reverse_list(ListNode* head);
ListNode* reverse_list_2(ListNode* head);
// 单链表翻转(自己写一遍)
ListNode* r1(ListNode* head);
ListNode* r2(ListNode* head);

// 合并两个有序单链表
void merge();
ListNode* merge_list(ListNode* l1, ListNode* l2);