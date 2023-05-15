/************************************************************************
*  FileName:	avl_tree
*  Description:	平衡二叉树
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

class AVLTree : BinaryTree
{
public:
    AVLTree()
        : BinaryTree()
    {}

    AVLTree(int val)
        : BinaryTree(val)
    {}

    virtual ~AVLTree() {}

    // 左旋
    BinaryTree* rotate_left(BinaryTree* root);

    // 右旋
    BinaryTree* rotate_right(BinaryTree* root);

    // 获取平衡因子
    int get_balance_factor()
    {
        // BalanceFactor = LeftNode.height - RightNode.height
        return left_child->get_height() - right_child->get_height();
    }

};
