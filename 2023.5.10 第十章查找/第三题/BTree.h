#pragma once
#ifndef BTREE_H
#define BTREE_H

#include<iostream>
using namespace std;

struct BTNode	//三阶B-树结点
{
	bool isleaf;		//是否为叶子结点 True 为是，FALSE为否

	int count;			//当前元素数量
	int data[3];		//元素

	BTNode* parent;		//父节点
	BTNode* child[4];	//孩子结点数组
	
	BTNode();
	BTNode(int x);
	void Insert(int x);	//叶子结点元素插入
};

class BTree
{
private:
	BTNode* root;
public:
	BTree();
	~BTree();
	void Insert(int x);				//插入元素对外接口
private:
	void Insert(BTNode* t, int x);	//插入元素内部实现
	void Destroy(BTNode* t);
};

#endif // !BTREE_H
