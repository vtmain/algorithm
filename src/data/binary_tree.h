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

	virtual ~BinaryTree() {}

	int get_data() { return data; }
	BinaryTree* get_left_child() { return left_child; }
	BinaryTree* get_right_child() { return right_child; }

	bool is_left_child(BinaryTree* node) { return (node == left_child); }
	bool is_right_child(BinaryTree* node) { return (node == right_child); }
	
	void set_left_node(BinaryTree* node) { left_child = node; }
	void set_right_node(BinaryTree* node) { right_child = node; }
	
	bool is_child(BinaryTree* node) { return (is_left_child(node) || is_right_child(node)); }
	void delete_child(BinaryTree* node);

	// 左插入
	void insert_left(int val);

	// 右插入
	void insert_right(int val);

	// 插入(虚函数，子类来实现)
	virtual void insert(int val) {};

	// 删除(虚函数，子类来实现)
	virtual bool remove(int val, BinaryTree* parent) { return false; };

	// 找到最大/最小值(虚函数，子类来实现)
	virtual int find_min_val() { return data; };
	virtual int find_max_val() { return data; };

	/////////////////////////////////////////////////////////////
	// 深度优先遍历(DFS, Depth-First Search), 常用来解决最大路径问题
	// 沿特定路径遍历到叶子节点再回溯(backtracking)进入临近路径继续遍历
	// 在输出遍历结果时，根据父节点相对子节点输出顺序不同，DFS可细分为先序、中序、后序三种

	// 前序遍历
	void pre_order();

	// 中序遍历
	void in_order();

	// 后序遍历
	void post_order();

	/////////////////////////////////////////////////////////////
	// 广度优先遍历(BFS, Breadth-First Search)，也叫宽度优先遍历
	// 按照节点深度逐层遍历树结构
	// 图的基础算法之一，常用来解决最短路径问题
	void bfs();

protected:
	int data;
	BinaryTree* left_child;
	BinaryTree* right_child;
};

class BinarySearchTree : public BinaryTree
{
public:
	BinarySearchTree() {}

	BinarySearchTree(int val)
		: BinaryTree(val)
	{}

	~BinarySearchTree() {}

	// 插入
	virtual void insert(int val);

	// 删除
	virtual bool remove(int val, BinaryTree* parent);

	// 找到最大/最小值
	virtual int find_min_val();
	virtual int find_max_val();
};

// 创建一棵树，根节点
BinaryTree* create_node(int val);
BinaryTree* create_tree();

// 遍历一棵树
void traverse(BinaryTree* root);

// test
void test_search_tree();