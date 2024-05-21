#include"Tree.h"

//---------------------------Tree类实现----------------------------
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
	count = tree.Get_count();
	Copy(tree.Get_root());
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

void Tree::Get_MaxIndex(int& max)
{
	max = 1;
	Get_MaxIndex(root, max,1);
}

void Tree::TurnToArray(char array[])			
{	
	if (root == NULL) { return; }
	TurnToArray(root,array,1);

}

void Tree::Get_MaxIndex(TreeNode* node, int& max, int cur)
{
	if (node == NULL) { return; }
	if (cur > max) { max = cur; }
	Get_MaxIndex(node->lchild, max, cur * 2);
	Get_MaxIndex(node->rchild, max, cur * 2 + 1);
}

void Tree::TurnToArray(TreeNode* node, char array[], int index)
{
	if (node == NULL) { return; }
	array[index] = node->data;
	TurnToArray(node->lchild, array, 2 * index);
	TurnToArray(node->rchild, array, 2 * index + 1);
}
