/************************************************************************
*  FileName:	rb_tree
*  Description:	红黑树
*  Author:		phil
*  Date:		2022-06-06
*  Version:		
************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <map>
#include <queue>
#include "binary_tree.h"

class RBTree : BinaryTree
{
public:
	RBTree()
		: BinaryTree()
	{}

	RBTree(int val)
		: BinaryTree(val)
	{}

	virtual ~RBTree() {}

};
