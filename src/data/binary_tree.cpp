#include "binary_tree.h"
#include <iostream>

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
	BinaryTree* node = new BinaryTree(val);
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

///////////////////////////////////////////////////////////

BinaryTree* create_tree(int val)
{
	BinaryTree* root = new BinaryTree(val);
	std::cout << "create tree root[" << root->get_data() << "] left[" << root->get_left_child() << "] right[" << root->get_right_child() << "]" << std::endl;
	return root;
}

