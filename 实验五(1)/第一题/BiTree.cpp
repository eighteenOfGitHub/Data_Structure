#include"BiTree.h"
//------------------------BNode����------------------------
BiTreeNode::BiTreeNode() {
	lChild = NULL;
	rChild = NULL; 
}
BiTreeNode::BiTreeNode(char data) {
	this->data = data;
	lChild = NULL;
	rChild = NULL;
} 
//------------------------BinaryTree��ʵ��------------------------
BiTree::BiTree()
{
	BiTreeNode* node = new BiTreeNode;
	node->lChild = NULL;
	node->rChild = NULL;
	root = node;
	count = 0;
}

BiTree::BiTree(const char* str)
{
	_createTree(root, str);
}

enum Child { LEFT, RIGHT };

void BiTree::_createTree(BiTreeNode*& node, const char* str)
{
	// ( �������ӽ��
	// �������ý�㹹��
	// ���������ӽ��
	// # ��������
	// �������������
	Stack<BiTreeNode*> stack;
	node = NULL;
	BiTreeNode* cur = NULL;	//��ǰ���
	BiTreeNode* top = NULL;	//ջ�����
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
			cur = new BiTreeNode;
			cur->data = *str;
			cur->lChild = NULL;
			cur->rChild = NULL;
			count++;
			{
				if (node == NULL)
					node = cur;
				else if (child == LEFT)
				{
					stack.get_top(top);
					top->lChild = cur;
				}
				else if (child == RIGHT)
				{
					stack.get_top(top);
					top->rChild = cur;
				}
			}
		}
		str++;
	}
}

// �������/�������/�������
void BiTree::preOrderTarverse() const
{
	if (count == 0)return;
	_preOrderTarverse(root,1);
	cout << endl;
}
void BiTree::inOrderTarverse() const
{
	if (count == 0)return;
	_inOrderTarverse(root, 1);
	cout << endl;
}
void BiTree::postOrderTarverse() const
{
	if (count == 0)return;
	_postOrderTarverse(root, 1);
	cout << endl;
}
void BiTree::_preOrderTarverse(BiTreeNode* node,int depth) const
{
	if (node == NULL) { return; }
	cout << node->data << ":"<<depth<<" ";
	_preOrderTarverse(node->lChild, depth + 1);
	_preOrderTarverse(node->rChild, depth + 1);
}
void BiTree::_inOrderTarverse(BiTreeNode* node, int depth) const
{
	if (node == NULL) { return; }
	_inOrderTarverse(node->lChild, depth + 1);
	cout << node->data << ":" << depth << " ";
	_inOrderTarverse(node->rChild, depth + 1);
}
void BiTree::_postOrderTarverse(BiTreeNode* node, int depth) const
{
	if (node == NULL) { return; }
	_postOrderTarverse(node->lChild, depth + 1);
	_postOrderTarverse(node->rChild, depth + 1);
	cout << node->data << ":" << depth << " ";
}

BiTree::BiTree(BiTree& tree)
{
	count = tree.get_count();
	root = Copy(tree.get_root());
}

BiTreeNode* BiTree::Copy(BiTreeNode* node)
{
	if (node == NULL)
	{
		return NULL;
	}
	else
	{
		BiTreeNode* temp = new BiTreeNode;
		temp->data = node->data;
		temp->lChild = Copy(node->lChild);
		temp->rChild = Copy(node->rChild);
		return temp;
	}
}

BiTree::~BiTree()
{
	destroyTree(root);
	root = NULL;
	count = 0;
}

void BiTree::destroyTree(BiTreeNode* node)
{
	if (node == NULL)return;
	destroyTree(node->lChild);
	destroyTree(node->rChild);
	delete node;
}