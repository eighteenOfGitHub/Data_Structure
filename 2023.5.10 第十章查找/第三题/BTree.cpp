#include"BTree.h"

//----------------------- BTNode �ṹ��Ĺ����뺯��ʵ�� --------------------------
BTNode::BTNode()
{
	count = 0;
	isleaf = true;
	parent = NULL;
	for (int i = 0; i < 3; i++)
	{
		child[i] = NULL;
	}
}

BTNode::BTNode(int x)
{
	count = 1;
	isleaf = true;
	parent = NULL;
	data[0] = x;
	for (int i = 0; i < 3; i++)
	{
		child[i] = NULL;
	}
}

void BTNode::Insert(int x)
{
	if (count == 0)data[0] = x;
	for (int i = 0; i < count; i++)
	{
		if (x < data[i])
		{
			for (int j = count; i < j; j--)
			{
				data[j] = data[j - 1];
			}
			data[i] = x;
		}
		else if (data[i] == x)break;
		else if (i + 1 == count)
		{
			data[count] = x;
		}
	}
	count++;
}

//----------------------- BTree ��Ĺ����뺯��ʵ�� --------------------------

BTree::BTree()
{
	root = new BTNode;
}

BTree::~BTree()
{
	Destroy(root);
}

void BTree::Insert(int x)
{
	Insert(root, x);
}

void BTree::Insert(BTNode* t, int x)
{
	//����
	if (t->isleaf)		//Ҷ�ӽ��
	{
		t->Insert(x);
	}
	else				//��Ҷ�ӽ��
	{
		if (t->count == 1)				//Ԫ�ظ���Ϊ 1
		{
			if (x > t->data[0])
				Insert(t->child[0], x);
			else
				Insert(t->child[1], x);
		}
		else if (t->count == 2)			//Ԫ�ظ���Ϊ 2
		{
			if (x < t->data[0])
				Insert(t->child[0], x);
			else if (x > t->data[1])
				Insert(t->child[2], x);
			else
				Insert(t->child[1], x);
		}
	}
	//���
	if (t->count == 3)
	{
		if (t->parent == NULL)	//���Ϊ�����
		{
			t->child[0] = new BTNode(t->data[0]);
			t->child[0]->parent = t;
			t->child[1] = new BTNode(t->data[2]);
			t->child[1]->parent = t;

			t->count = 1;
			t->data[0] = t->data[1];
			t->isleaf = false;
		}
		else					//�����Ϊ�����
		{
			//����
			BTNode* node1 = new BTNode(t->data[0]);
			node1->parent = t->parent;
			node1->child[0] = t->child[0];
			node1->child[1] = t->child[1];
			for (int i = 0; i < 4; i++)
			{
				if (node1->child[i] != NULL)node1->isleaf = false;
			}
			BTNode* node2 = new BTNode(t->data[2]);
			node2->parent = t->parent;
			node2->child[0] = t->child[2];
			node2->child[1] = t->child[3];
			for (int i = 0; i < 4; i++)
			{
				if (node1->child[i] != NULL)node1->isleaf = false;
			}
			//����
			if (t->parent->count == 1)	//���������Ԫ������Ϊ 1
			{
				if (t->data[1] < t->parent->data[0])
				{
					t->parent->data[1] = t->parent->data[0];
					t->parent->data[0] = t->data[1];
					t->parent->count++;
					t->parent->child[2] = t->parent->child[1];
					t->parent->child[0] = node1;
					t->parent->child[1] = node2;
				}
				else
				{
					t->parent->data[1] = t->data[1];
					t->parent->count++;
					t->parent->child[1] = node1;
					t->parent->child[2] = node2;
				}
			}
			else						//���������Ԫ������Ϊ 2
			{
				if (t->data[1] < t->parent->data[0])
				{
					t->parent->data[2] = t->parent->data[1];
					t->parent->data[1] = t->parent->data[0];
					t->parent->data[0] = t->data[1];
					t->parent->count++;
					t->parent->child[3] = t->parent->child[2];
					t->parent->child[2] = t->parent->child[1];
					t->parent->child[0] = node1;
					t->parent->child[1] = node2;
				}
				else if (t->data[1] < t->parent->data[2])
				{
					t->parent->data[2] = t->data[1];
					t->parent->count++;
					t->parent->child[2] = node1;
					t->parent->child[3] = node2;
				}
				else
				{
					t->parent->data[2] = t->parent->data[1];
					t->parent->data[1] = t->data[1];
					t->parent->count++;
					t->parent->child[3] = t->parent->child[2];
					t->parent->child[1] = node1;
					t->parent->child[2] = node2;
				}
			}
		}
	}
}

void BTree::Destroy(BTNode* t)
{
	if (t == NULL)
	{
		return;
	}
	for (int i = 0; t->child[i] != NULL || i< t->count; i++)
	{
		Destroy(t->child[i]);
	}
	delete t;
	t = NULL;
}