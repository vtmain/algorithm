#include "slist.h"
#include <iostream>

ListNode* create_list_node(int val)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->next = NULL;
	return node;
}
ListNode* create_list(int arr[], int len)
{
	if (len <= 0)
		return NULL;

	// 尾插
	ListNode* cur = NULL;
	for (int i = len - 1; i >= 0; --i)
	{
		ListNode* node = create_list_node(arr[i]);
		node->next = cur;
		cur = node;
	}
	dump_list(cur, "create");
	return cur;
}

void dump_list(ListNode* head, char* txt/* = NULL*/)
{
	if (txt)
		std::cout << txt << " ";
	std::cout << "list: [";

	ListNode* cur = head;
	while (cur)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}

	std::cout << "]" << std::endl;
}

void process_slist()
{
	// 单链表反转
	//reverse();

	// 合并两个有序链表
	merge();
}

//////////////////////////////////////////////////////////////////////////

// 单链表反转
void reverse()
{
	int arr[] = {1, 2, 3, 4, 5};
	ListNode* head = create_list(arr, sizeof(arr) / sizeof(int));

	ListNode* rhead = r2(head);
	dump_list(rhead, "reverse");
}

// 递归  recurse
ListNode* reverse_list(ListNode* head)
{
	// 最后一个节点，返回的是自己，实现找到rhead
	if (head == NULL || head->next == NULL)
		return head;

	// 先对剩余节点做递归(逻辑顺序)，最后一个节点返回的head，即为rhead
	// 在整个递归过程中，rhead取到后就不再变化了，一直返回
	ListNode* rest = head->next;
	ListNode* rhead = reverse_list(rest);

	// 递归返回上一层后:
	//   把下一层的next指向自己，实现反转(rest是原本的下一个节点，head是原本的当前节点)
	//   把自己的next置空，留到上一层处理，没有上一层的话，就保持空值，自然就是反转后的尾结点
	rest->next = head;
	head->next = NULL;
	return rhead;
}


// 迭代  while
ListNode* reverse_list_2(ListNode* head)
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

//////////////////////////////////////////////////////////////////////////

// 合并两个有序单链表
void merge()
{
	int arr1[] = {1, 3, 5, 7, 9};
	ListNode* h1 = create_list(arr1, sizeof(arr1) / sizeof(int));
	int arr2[] = {2, 4, 6, 8};
	ListNode* h2 = create_list(arr2, sizeof(arr2) / sizeof(int));

	ListNode* hn = merge_list(h1, h2);
	dump_list(hn, "after merge");
}

// 递归合并
ListNode* merge_list(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	if (l1->data <= l2->data)
	{
		l1->next = merge_list(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = merge_list(l2->next, l1);
		return l2;
	}
}

//////////////////////////////////////////////////////////////////////////