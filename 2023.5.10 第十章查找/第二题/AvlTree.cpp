#include"AvlTree.h"
//----------------------------函数的构造和析构---------------------------------------
AvlTree::AvlTree()
{
	root = NULL;
}
AvlTree::~AvlTree()
{
	Delete(root);
}

//----------------------------遍历---------------------------------------

void AvlTree::PreorderTraversal()		//先序遍历对外接口
{
	PreorderTraversal(root);
}
void AvlTree::InorderTraversal()		//中序遍历对外接口
{
	InorderTraversal(root);
}
void AvlTree::PreorderTraversal(AvlNode* t)	//先序遍历
{
	if (t == NULL) { return; }
	cout << t->data << " ";
	PreorderTraversal(t->lchild);
	PreorderTraversal(t->rchild);
}
void AvlTree::InorderTraversal(AvlNode* t)	//中序遍历
{
	if (t == NULL) { return; }
	InorderTraversal(t->lchild);
	cout << t->data << " ";
	InorderTraversal(t->rchild);
}
//----------------------------插入---------------------------------------

void AvlTree::Insert(int x)
{
	Insert(root, x);
}

void AvlTree::Insert(AvlNode* &t, int x)
{
	if (t == NULL)
	{
		t= new AvlNode(x);
		return;
	}
	else if (x < t->data)
	{
		Insert(t->lchild, x);
		if (GetHeight(t->lchild) - GetHeight(t->rchild) > 1)	//左子树高度 比 右子树高度 大2
		{
			AvlNode* left = t->lchild;
			if (GetHeight(left->lchild) > GetHeight(left->rchild))	//LL型
			{
				t = LLadjust(t);
			}
			else													//LR型
			{
				t = LRadjust(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->rchild, x);
		if (GetHeight(t->rchild) - GetHeight(t->lchild) > 1)	//右子树高度 比 左子树高度 大2
		{
			AvlNode* right = t->rchild;
			if (GetHeight(right->lchild) > GetHeight(right->rchild))	//RL型
			{
				t = RLadjust(t);
			}
			else														//RR型
			{
				t = RRadjust(t);
			}
		}
	}
}

//----------------------------位置调整---------------------------------------

AvlNode* AvlTree::LLadjust(AvlNode* a)
{
	AvlNode* b = a->lchild;
	a->lchild = b->rchild;
	b->rchild = a;
	return b;
}
AvlNode* AvlTree::LRadjust(AvlNode* a)
{
	AvlNode* c = a->lchild->rchild;
	AvlNode* b = a->lchild;
	b->rchild = c->lchild;
	a->lchild = c->rchild;
	c->lchild = b;
	c->rchild = a;
	return c;
}
AvlNode* AvlTree::RLadjust(AvlNode* a)
{
	AvlNode* c = a->rchild->lchild;
	AvlNode* b = a->rchild;
	b->lchild = c->rchild;
	a->rchild = c->lchild;
	c->lchild = a;
	c->rchild = b;
	return c;
}
AvlNode* AvlTree::RRadjust(AvlNode* a)
{
	AvlNode* b = a->rchild;
	a->rchild = b->lchild;
	b->lchild = a;
	return b;

}
//----------------------------工具包---------------------------------------
int max(const int n, const int m)
{
	return (m > n) ? m : n;
}

//----------------------------相关功能---------------------------------------

int AvlTree::GetHeight(AvlNode* t)
{
	if (t == NULL)return 0;
	return max(GetHeight(t->lchild), GetHeight(t->rchild))+1;
}

void AvlTree::Delete(AvlNode* t)
{
	if (t == NULL)return;
	Delete(t->lchild);
	Delete(t->rchild);
	delete t;
}
