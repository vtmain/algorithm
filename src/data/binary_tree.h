/************************************************************************
*  FileName:	binary_tree
*  Description:	二叉树
*  Author:		phil
*  Date:		2022-04-25
*  Version:		
************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <map>

class BinaryTree
{
public:
	BinaryTree()
		: data(0), left_child(NULL), right_child(NULL)
	{}

	BinaryTree(int val)
		: data(val), left_child(NULL), right_child(NULL)
	{}

	~BinaryTree() {}

	int get_data() { return data; }
	BinaryTree* get_left_child() { return left_child; }
	BinaryTree* get_right_child() { return right_child; }

	// 左插入
	void insert_left(int val);

	// 右插入
	void insert_right(int val);

private:
	int data;
	BinaryTree* left_child;
	BinaryTree* right_child;
};

// 创建一棵树，根节点
BinaryTree* create_tree(int val);

// 