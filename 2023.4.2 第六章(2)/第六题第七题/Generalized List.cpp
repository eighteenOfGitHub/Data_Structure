#include"Generalized List.h"


void GList::_CreateGList(GListNode*& link, const char*& str)
{
	//����ͷ���
	GListNode* head = new GListNode(HEAD, NULL);
	head->next = NULL;
	link = head;
	//���ڼ�¼��ǰָ��
	GListNode* cur = link;
	str++;

	while (*str != '\0')
	{
		if (_IsValue(*str))	//�����ǰɨ�赽���ַ���ֵ
		{
			GListNode* newnode = new GListNode(VALUE, *str);
			newnode->next = NULL;
			cur->next = newnode;
			cur = cur->next;
			str++;
		}
		else if (*str == '(')	//�����'(',�򴴽��ӱ�ڵ�
		{
			GListNode* subnode = new GListNode(SUB, NULL);
			subnode->next = NULL;
			cur->next = subnode;
			cur = cur->next;
			_CreateGList(cur->sublist, str);	//�ݹ鴴���ӱ�
		}
		else if (*str == ')')	//�ӱ�������
		{
			str++;
			return;
		}
		else	//��Ч�ַ�����
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
			size += _Size(cur->sublist);	//�����ӱ���еݹ�
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
	int depth = 1, maxdepth = 1;	//maxdepthΪĿǰ������
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
	GListNode* cur = link;	//�����α�
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


//�ܽ�һ��
//Ϊʲô�����ӽڵ�Ҫ����ȥ����ָ�룿
//�տ�ʼ�Ҵ���һ��ָ���ʱ���ҷ��ִ�����ɺ�gl = NULL��Ϊʲô��
//��Ϊû��һ��������¼gl��һ���ڵ�ĵ�ַ������������Ҳ������ˡ�
//��ʱ�����Ҫһ������ָ�룬ָ���ͷ�ڵ�ĵ�ַ��

 //�ܽ����
//�ⲿ�����Զ����������ͣ����ö�������ӿڣ���ǿ���ṹ��ȫ�ԣ������޲���

//˼��һ��
//Ϊʲô������ȣ�ֵ��㳤����Ϊ������
//�������ȵ����������е����Ϊ1�����ݽṹ���ԣ����룬ɾ���Ȳ�����Ϊ���ӣ�
//���������ı仯����ͳ�ƣ������ڸ��ӳ����в���ɾ������������Զ��������ȵĲ���
//������ԣ�����ȵ�����һ��������������ʱ��