#include"AvlTree.h"
//----------------------------�����Ĺ��������---------------------------------------
AvlTree::AvlTree()
{
	root = NULL;
}
AvlTree::~AvlTree()
{
	Delete(root);
}

//----------------------------����---------------------------------------

void AvlTree::PreorderTraversal()		//�����������ӿ�
{
	PreorderTraversal(root);
}
void AvlTree::InorderTraversal()		//�����������ӿ�
{
	InorderTraversal(root);
}
void AvlTree::PreorderTraversal(AvlNode* t)	//�������
{
	if (t == NULL) { return; }
	cout << t->data << " ";
	PreorderTraversal(t->lchild);
	PreorderTraversal(t->rchild);
}
void AvlTree::InorderTraversal(AvlNode* t)	//�������
{
	if (t == NULL) { return; }
	InorderTraversal(t->lchild);
	cout << t->data << " ";
	InorderTraversal(t->rchild);
}
//----------------------------����---------------------------------------

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
		if (GetHeight(t->lchild) - GetHeight(t->rchild) > 1)	//�������߶� �� �������߶� ��2
		{
			AvlNode* left = t->lchild;
			if (GetHeight(left->lchild) > GetHeight(left->rchild))	//LL��
			{
				t = LLadjust(t);
			}
			else													//LR��
			{
				t = LRadjust(t);
			}
		}
	}
	else if (x > t->data)
	{
		Insert(t->rchild, x);
		if (GetHeight(t->rchild) - GetHeight(t->lchild) > 1)	//�������߶� �� �������߶� ��2
		{
			AvlNode* right = t->rchild;
			if (GetHeight(right->lchild) > GetHeight(right->rchild))	//RL��
			{
				t = RLadjust(t);
			}
			else														//RR��
			{
				t = RRadjust(t);
			}
		}
	}
}

//----------------------------λ�õ���---------------------------------------

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
//----------------------------���߰�---------------------------------------
int max(const int n, const int m)
{
	return (m > n) ? m : n;
}

//----------------------------��ع���---------------------------------------

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
