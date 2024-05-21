#pragma once
#include<iostream>
#include"Stack.hpp"
using namespace std;

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

	void Preorder() const;					//先序遍历输出接口
	TreeNode* get_root() { return root; }	//获得根结点指针
	int get_count()const { return count; }	//获得结点数

private:
	void CreateTree(TreeNode*& node, const char* str);	//广义表构造函数实现
	void Preorder(TreeNode* node) const;				//先序遍历输出实现
	void DestroyTree(TreeNode* node);					//删除结点实现
	TreeNode* Copy(TreeNode* node);						//复制结点实现
private:
	TreeNode* root;					//根节点包含指针域
	int count;
};

Tree::Tree()
{
	TreeNode* node = new TreeNode;
	node->lchild = NULL;
	node->rchild = NULL;
	root = node;
	count = 0;
}

Tree::Tree(const char* str)
{
	CreateTree(root, str);
}

enum Child { LEFT, RIGHT };
void Tree::CreateTree(TreeNode*& node, const char* str)
{
	// ( 构造左子结点
	// ）结束该结点构造
	// ，构造右子结点
	// # 结束构造
	// 其他则更新数据
	Stack<TreeNode*> stack;
	node = NULL;
	TreeNode* cur = NULL;	//当前结点
	TreeNode* top = NULL;	//栈顶结点
	Child child = LEFT;		//记录是左子结点还是右子结点
	while (*str != '#')
	{
		if (*str == '(')
		{
			stack.push(cur);
			child = LEFT;
		}
		else if (*str == ')')
		{
			stack.pop();
		}
		else if (*str == ',')
		{
			child = RIGHT;
		}
		else
		{
			cur = new TreeNode;
			cur->data = *str;
			cur->lchild = NULL;
			cur->rchild = NULL;
			count++;
			{
				if (node == NULL)
					node = cur;
				else if (child == LEFT)
				{
					stack.get_top(top);
					top->lchild = cur;
				}
				else if (child == RIGHT)
				{
					stack.get_top(top);
					top->rchild = cur;
				}
			}
		}
		str++;
	}
}

void Tree::Preorder() const
{
	if (count == 0)return;
	Preorder(root);
}

void Tree::Preorder(TreeNode* node) const
{
	if (node == NULL) { return; }
	cout << node->data;
	Preorder(node->lchild);
	Preorder(node->rchild);
}

Tree::Tree(Tree& tree)
{
	count = tree.get_count();
	root = Copy(tree.get_root());
}

TreeNode* Tree::Copy(TreeNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	else
	{
		TreeNode* temp = new TreeNode;
		temp->data = node->data;
		temp->lchild = Copy(node->lchild);
		temp->rchild = Copy(node->rchild);
		return temp;
	}
}

Tree::~Tree()
{
	DestroyTree(root);
	root = NULL;
	count = 0;
}

void Tree::DestroyTree(TreeNode* node)
{
	if (node == NULL)return;
	DestroyTree(node->lchild);
	DestroyTree(node->rchild);
	delete node;
}



