#include"Generalized List.h"


void GList::_CreateGList(GListNode*& link, const char*& str)
{
	//创建头结点
	GListNode* head = new GListNode(HEAD, NULL);
	head->next = NULL;
	link = head;
	//用于记录当前指针
	GListNode* cur = link;
	str++;

	while (*str != '\0')
	{
		if (_IsValue(*str))	//如果当前扫描到的字符是值
		{
			GListNode* newnode = new GListNode(VALUE, *str);
			newnode->next = NULL;
			cur->next = newnode;
			cur = cur->next;
			str++;
		}
		else if (*str == '(')	//如果是'(',则创建子表节点
		{
			GListNode* subnode = new GListNode(SUB, NULL);
			subnode->next = NULL;
			cur->next = subnode;
			cur = cur->next;
			_CreateGList(cur->sublist, str);	//递归创建子表
		}
		else if (*str == ')')	//子表创建结束
		{
			str++;
			return;
		}
		else	//无效字符跳过
		{
			str++;
		}
	}
}

bool GList::_IsValue(const char ch)
{
	if (ch >= 'a' && ch <= 'z' ||
		ch >= 'A' && ch <= 'Z' ||
		ch >= '0' && ch <= '(')
		return true;
	return false;
}

int GList::Size()
{
	return _Size(_front);
}

int GList::_Size(GListNode* head)
{
	int size = 0;
	GListNode* cur = head;
	while (cur != NULL)
	{
		if (cur->type == VALUE)
			size++;
		else if (cur->type == SUB)
			size += _Size(cur->sublist);	//遇到子表进行递归
		cur = cur->next;
	}
	return size;
}

int GList::Depth()
{
	return _Depth(_front);
}

int GList::_Depth(GListNode* head)
{
	int depth = 1, maxdepth = 1;	//maxdepth为目前最大深度
	GListNode* cur = head;
	while (cur != NULL)
	{
		if (cur->type == SUB)
			depth += _Depth(cur->sublist);
		if (depth > maxdepth)
		{
			maxdepth = depth;
			depth = 1;
		}
		cur = cur->next;
	}
	return maxdepth;
}

void GList::Print()
{
	_Print(_front);
}

void GList::_Print(GListNode* link)
{
	GListNode* cur = link;	//遍历游标
	while (cur != NULL)
	{
		if (cur->type == VALUE)
		{
			cout << cur->data;
			if (cur->next != NULL)
				cout << ", ";
		}
		else if (cur->type == HEAD)
			cout << "( ";
		else if (cur->type == SUB)
		{
			_Print(cur->sublist);
			if (cur->next != NULL)
				cout << ", ";
		}
		cur = cur->next;
	}
	cout << " )";
}


//总结一：
//为什么构造子节点要传进去二级指针？
//刚开始我传进一级指针的时候，我发现创建完成后，gl = NULL，为什么？
//因为没有一个变量记录gl第一个节点的地址啊，所以最后找不到它了。
//这时候就需要一个二级指针，指向该头节点的地址。

 //总结二：
//外部操作自定义数据类型，设置独立对外接口，加强数结构安全性，减少无操作

//思考一：
//为什么不把深度，值结点长度设为参数？
//广义表相比单链表，链队列等深度为1的数据结构而言，插入，删除等操作更为复杂，
//对于总数的变化不好统计，并且在复杂程序中插入删除操作次数会远多于求深度的操作
//总体而言，求深度单另设一函数，减少运算时间