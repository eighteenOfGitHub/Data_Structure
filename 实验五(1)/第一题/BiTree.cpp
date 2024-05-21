#include"BiTree.h"
//------------------------BNode构造------------------------
BiTreeNode::BiTreeNode() {
	lChild = NULL;
	rChild = NULL; 
}
BiTreeNode::BiTreeNode(char data) {
	this->data = data;
	lChild = NULL;
	rChild = NULL;
} 
//------------------------BinaryTree类实现------------------------
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
	// ( 构造左子结点
	// ）结束该结点构造
	// ，构造右子结点
	// # 结束构造
	// 其他则更新数据
	Stack<BiTreeNode*> stack;
	node = NULL;
	BiTreeNode* cur = NULL;	//当前结点
	BiTreeNode* top = NULL;	//栈顶结点
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

// 先序遍历/中序遍历/后序遍历
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