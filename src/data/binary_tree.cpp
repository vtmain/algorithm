#include "binary_tree.h"
#include <iostream>

// https://zhuanlan.zhihu.com/p/30918614

/*
*                  【5】
*              /           \
*          【3】           【7】
*          /   \           /   \
*     【2】    【4】   【6】   【8】
* 
*/

void BinaryTree::insert_left(int val)
{
	BinaryTree* node = new BinaryTree(val);
	if (this->left_child == NULL)
	{
		this->left_child = node;
		node = NULL;
	}
	else
	{
		node->left_child = this->left_child;
		this->left_child = node;
	}
}

void BinaryTree::insert_right(int val)
{
	BinaryTree* node = create_tree(val);
	if (this->right_child == NULL)
	{
		this->right_child = node;
		node = NULL;
	}
	else
	{
		node->right_child = this->right_child;
		this->right_child = node;
	}
}

// 前序遍历（自己 - 左 - 右）
void BinaryTree::pre_order()
{
	std::cout << this->data << " ";

	if (this->left_child)
		this->left_child->pre_order();

	if (this->right_child)
		this->right_child->pre_order();
}

// 中序遍历（左 - 自己 - 右）
void BinaryTree::in_order()
{
	if (this->left_child)
		this->left_child->in_order();

	std::cout << this->data << " ";

	if (this->right_child)
		this->right_child->in_order();
}

// 后序遍历（左 - 右 - 自己）
void BinaryTree::post_order()
{
	if (this->left_child)
		this->left_child->post_order();

	if (this->right_child)
		this->right_child->post_order();

	std::cout << this->data << " ";
}

// 广度优先搜索BFS
void BinaryTree::bfs()
{
	std::queue<BinaryTree*> _queue;
	_queue.push(this);
	std::cout << "       bfs: ";

	while (!_queue.empty())
	{
		BinaryTree* node = _queue.front();
		_queue.pop();
		std::cout << node->get_data() << " ";

		if (node->get_left_child())
			_queue.push(node->get_left_child());

		if (node->right_child)
			_queue.push(node->right_child);
	}
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////

BinaryTree* create_tree(int val)
{
	BinaryTree* root = new BinaryTree(val);
	std::cout << "create tree node[" << root->get_data() << "] left[" << root->get_left_child() << "] right[" << root->get_right_child() << "]" << std::endl;
	return root;
}



void test_tree()
{
	BinaryTree* root = create_tree(5);
	root->insert_left(3);
	root->insert_right(7);

	root->get_left_child()->insert_left(2);
	root->get_left_child()->insert_right(4);

	root->get_right_child()->insert_left(6);
	root->get_right_child()->insert_right(8);

	// ----------------------------

	// 前序遍历
	std::cout << "pre  order: ";
	root->pre_order();
	std::cout << std::endl;

	// 中序遍历
	std::cout << "in   order: ";
	root->in_order();
	std::cout << std::endl;

	// 后序遍历
	std::cout << "post order: ";
	root->post_order();
	std::cout << std::endl;

	// 广度优先搜索 BFS
	root->bfs();
}