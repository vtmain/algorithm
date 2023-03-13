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
	// 最后一个节点，返回的是自己，实现找到rhead
	if (head == NULL || head->next == NULL)
		return head;

	// 先对剩余节点做递归(逻辑顺序)，最后一个节点返回的head，即为rhead
	// 在整个递归过程中，rhead取到后就不再变化了，一直返回
	ListNode* rest = head->next;
	ListNode* rhead = reverse(rest);

	// 递归返回上一层后:
	//   把下一层的next指向自己，实现反转(rest是原本的下一个节点，head是原本的上一个节点)
	//   把自己的next置空，留到上一层处理，没有上一层的话，就保持空值，自然就是反转后的尾结点
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