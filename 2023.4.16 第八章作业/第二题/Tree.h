#pragma once
#ifndef TREE_H
#define TREE_H

#include<iostream>
#include"Stack.hpp"
#include"Linked List.h"
using namespace std;

//---------------------------Tree类----------------------------
struct TreeNode
{
	char data;
	TreeNode* lchild, * rchild;
};

class Tree
{
public:
	Tree();							//默认构造函数
	Tree(const char* str);			//广义表构造函数接口
	Tree(Tree& tree);				//拷贝构造函数
	~Tree();						//析构函数

	TreeNode* Get_root() { return root; }	//获得根结点指针
	int Get_count()const { return count; }	//获得结点数

	void Preorder() const;					//先序遍历输出接口
	void Get_MaxIndex(int& max);			//获得二叉树转顺序表最大序号接口
	void TurnToArray(char array[]);			//二叉树转顺序表接口

private:	
	void CreateTree(TreeNode*& node, const char* str);			//广义表构造函数实现
	void Preorder(TreeNode* node) const;						//先序遍历输出实现
	void DestroyTree(TreeNode* node);							//删除结点实现
	TreeNode* Copy(TreeNode* node);								//复制结点实现

	void Get_MaxIndex(TreeNode* node, int& max, int cur);		//获得二叉树转顺序表最大序号实现
	void TurnToArray(TreeNode* node, char array[],int index);	//二叉树转顺序表实现

private:
	TreeNode* root;					//根节点包含指针域
	int count;
};
#endif // !TREE_H