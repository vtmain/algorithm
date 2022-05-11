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
	BinaryTree* node = create_tree(val);
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

void BinaryTree::delete_child(BinaryTree* node)
{
	if (node == left_child)
	{
		delete left_child;
		left_child = NULL;
	}
	else if (node == right_child)
	{
		delete right_child;
		right_child = NULL;
	}
}

///////////////////////////////////////////////////////////

void BinarySearchTree::insert(int val)
{
	if (val < data && left_child)
		left_child->insert(val);
	else if (val < data)
		insert_left(val);
	else if (val > data && right_child)
		right_child->insert(val);
	else
		insert_right(val);
}

bool BinarySearchTree::remove(int val, BinaryTree* parent)
{
	if (val < data && left_child)
		return left_child->remove(val, this);
	else if (val < data)
		return false;
	else if (val > data && right_child)
		return right_child->remove(val, this);
	else if (val > data)
		return false;
	else	// 等于，自己就是需要移除的节点
	{
		if (left_child == NULL && right_child == NULL && parent->is_child(this))
			parent->delete_child(this);
		else if (left_child && right_child == NULL && parent->is_left_child(this))
		{
			parent->delete_child(this);
			parent->set_left_node(left_child);
		}
		else if (left_child && right_child == NULL && parent->is_right_child(this))
		{
			parent->delete_child(this);
			parent->set_right_node(left_child);
		}
		else if (left_child == NULL && right_child && parent->is_left_child(this))
		{
			parent->delete_child(this);
			parent->set_left_node(right_child);
		}
		else if (left_child == NULL && right_child && parent->is_right_child(this))
		{
			parent->delete_child(this);
			parent->set_right_node(right_child);
		}
		else	// 自己的左右节点都不为空
		{
			// 找到自己右子树中最小值，放到当前自己位置，然后删除那个最小值节点
			data = right_child->find_min_val();
			right_child->remove(data, this);
		}
		return true;
	}
}

int BinarySearchTree::find_min_val()
{
	if (left_child)
		return left_child->find_min_val();
	else
		return data;
}

///////////////////////////////////////////////////////////

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
		std::cout << node->data << " ";

		if (node->left_child)
			_queue.push(node->left_child);

		if (node->right_child)
			_queue.push(node->right_child);
	}
	std::cout << std::endl;
}

BinaryTree* create_tree(int val)
{
	BinaryTree* root = new BinarySearchTree(val);
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

void test_search_tree()
{
	BinaryTree* root = create_tree(5);
	int arr[] = {3, 7, 2, 4, 6, 8, 9, 1};
	int len = (int)sizeof(arr) / (int)sizeof(int);
	for (int i = 0; i < len; i++)
	{
		root->insert(arr[i]);
	}
	root->bfs();

	// 不能删除root节点
	root->remove(7, root);
	root->bfs();
}