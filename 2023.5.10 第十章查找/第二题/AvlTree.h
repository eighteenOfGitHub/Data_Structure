#pragma once
#include<iostream>
using namespace std;

struct AvlNode
{
	int data;		//值域
	AvlNode* rchild, * lchild;
	AvlNode(int d)
	{
		data = d;
		rchild = NULL;
		lchild = NULL; 
	}
};

class AvlTree
{
public:
	//构造函数
	AvlTree();
	~AvlTree();

	void Insert(int x);			//插入元素对外接口

	void PreorderTraversal();	//先序遍历对外接口
	void InorderTraversal();	//中序遍历对外接口

private:
	//插入元素内部实现
	void Insert(AvlNode* &t, int x);


	//四种类型转化
	AvlNode* LLadjust(AvlNode* a);
	AvlNode* LRadjust(AvlNode* a);
	AvlNode* RLadjust(AvlNode* a);
	AvlNode* RRadjust(AvlNode* a);

	//遍历
	void PreorderTraversal(AvlNode* t); //前序遍历
	void InorderTraversal(AvlNode* t);	//中序遍历

	//相关功能
	int GetHeight(AvlNode* t);			//得到高度
	void Delete(AvlNode* t);			//删除以此结点为根的树

private:
	AvlNode* root;
};