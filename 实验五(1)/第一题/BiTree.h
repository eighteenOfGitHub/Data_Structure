#ifndef BINARYTREE_H
#define BINARYTREE_H
#pragma once
#include<iostream>
#include"Stack.hpp"
using namespace std;

struct BiTreeNode
{
	char data;
	BiTreeNode* lChild, * rChild;
	BiTreeNode();
	BiTreeNode(char data);
};

class BiTree
{
public:
	BiTree();							//默认构造函数
	BiTree(const char* str);			//广义表构造函数接口
	BiTree(BiTree& tree);			//拷贝构造函数
	~BiTree();							//析构函数

	void preOrderTarverse() const;				//先序遍历输出接口
	void inOrderTarverse() const;				//中序遍历输出接口
	void postOrderTarverse() const;				//后序遍历输出接口
	BiTreeNode* get_root() { return root; }			//获得根结点指针
	int get_count()const { return count; }		//获得结点数

private:
	void _createTree(BiTreeNode*& node, const char* str);	//广义表构造函数实现
	void _preOrderTarverse(BiTreeNode* node, int depth) const;		//先序遍历输出实现
	void _inOrderTarverse(BiTreeNode* node, int depth) const;		//中序遍历输出实现
	void _postOrderTarverse(BiTreeNode* node, int depth) const;		//后序遍历输出实现
	void destroyTree(BiTreeNode* node);					//删除结点实现
	BiTreeNode* Copy(BiTreeNode* node);					//复制结点实现
private:
	BiTreeNode* root;					//根节点包含指针域
	int count;
};
#endif // !BINARYTREE_H
