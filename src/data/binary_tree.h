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
#include <queue>

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

	/////////////////////////////////////////////////////////////
	// 深度优先遍历(DFS)
	// 沿特定路径遍历到叶子节点再回溯(backtracking)进入临近路径继续遍历
	// 在输出遍历结果时，根据父节点相对子节点输出顺序不同，DFS可细分为先序、中序、后序三种

	// 前序遍历
	void pre_order();

	// 中序遍历
	void in_order();

	// 后序遍历
	void post_order();

	/////////////////////////////////////////////////////////////
	// 广度优先遍历(BFS)
	void bfs();

private:
	int data;
	BinaryTree* left_child;
	BinaryTree* right_child;
};

// 创建一棵树，根节点
BinaryTree* create_tree(int val);

// test
void test_tree();