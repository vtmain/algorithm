#include "slist.h"
#include <iostream>


ListNode* init_list(int n)
{
	ListNode* head = new ListNode;
	head->data = 0;
	head->next = NULL;

	ListNode* cur = head;
	ListNode* prev = head;
	for (int i = 1; i < n; i++)
	{
		cur = new ListNode;
		cur->data = i;
		prev->next = cur;
		prev = cur;
		cur = NULL;
	}
	return head;
}

void dump_list(ListNode* head)
{
	std::cout << "slist: [";
	ListNode* cur = head;
	while (cur)
	{
		std::cout << cur->data;
		if (cur->next)
			std::cout << ", ";
		cur = cur->next;
	}
	std::cout << "]" << std::endl;
}

void process_slist()
{
	ListNode* head = init_list(10);
	dump_list(head);

	ListNode* rhead = r2(head);

	dump_list(rhead);
}

//////////////////////////////////////////////////////////////////////////

// 递归  recurse
ListNode* reverse(ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	ListNode* rest = head->next;
	ListNode* rhead = reverse(rest);
	rest->next = head;
	head->next = NULL;
	return rhead;
}


// 迭代  while
ListNode* reverse2(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* cur = head;
	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}

ListNode* r1(ListNode* head)
{
	if (!head || !head->next)
		return head;

	ListNode* rhead = r1(head->next);
	head->next->next = head;
	head->next = NULL;
	return rhead;
}

ListNode* r2(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* cur = head;

	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}