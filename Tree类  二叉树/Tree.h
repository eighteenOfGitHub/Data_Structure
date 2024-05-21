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
	Tree();							//Ĭ�Ϲ��캯��
	Tree(const char* str);			//������캯���ӿ�
	Tree(Tree& tree);				//�������캯��
	~Tree();						//��������

	void Preorder() const;					//�����������ӿ�
	TreeNode* get_root() { return root; }	//��ø����ָ��
	int get_count()const { return count; }	//��ý����

private:
	void CreateTree(TreeNode*& node, const char* str);	//������캯��ʵ��
	void Preorder(TreeNode* node) const;				//����������ʵ��
	void DestroyTree(TreeNode* node);					//ɾ�����ʵ��
	TreeNode* Copy(TreeNode* node);						//���ƽ��ʵ��
private:
	TreeNode* root;					//���ڵ����ָ����
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
	// ( �������ӽ��
	// �������ý�㹹��
	// ���������ӽ��
	// # ��������
	// �������������
	Stack<TreeNode*> stack;
	node = NULL;
	TreeNode* cur = NULL;	//��ǰ���
	TreeNode* top = NULL;	//ջ�����
	Child child = LEFT;		//��¼�����ӽ�㻹�����ӽ��
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



