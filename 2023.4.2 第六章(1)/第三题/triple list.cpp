#include"triple list.h"
TripleList::TripleList()
{
	Tuple* tuple = new Tuple;
	tuple->next = NULL;
	front = tuple;
	rear = tuple;
	count = 0;
}

TripleList::TripleList(int A[][MAX])	//三元表构造函数
{
	Tuple* tuple = new Tuple;
	tuple->next = NULL;
	front = tuple;
	rear = tuple;
	count = 0;

	Tuple* PA = front;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (A[i][j] != 0)
			{
				Tuple* tuple = new Tuple;
				tuple->ti = i;
				tuple->tj = j;
				tuple->data = A[i][j];
				tuple->next = NULL;

				PA->next = tuple;
				PA = tuple;
				rear = PA;
				count++;
			}
}

TripleList::TripleList(TripleList& tl)			//三元表拷贝构造
{
	Tuple* tuple = new Tuple;
	tuple->next = NULL;
	front = tuple;
	rear = tuple;
	count = 0;

	Tuple* PA = front;
	Tuple* PB = tl.get_front()->next;
	while (PB != NULL)
	{
		Tuple* tuple = new Tuple;
		tuple->ti = PB->ti;
		tuple->tj = PB->tj;
		tuple->data = PB->data;
		tuple->next = NULL;

		PA->next = tuple;
		PA = tuple;
		rear = PA;
		count++;

		PB = PB->next;
	}
}

TripleList::TripleList(const TripleList& tl)			//三元表拷贝构造
{
	Tuple* tuple = new Tuple;
	tuple->next = NULL;
	front = tuple;
	rear = tuple;
	count = 0;

	Tuple* PA = front;
	Tuple* PB = tl.get_front()->next;
	while (PB != NULL)
	{
		Tuple* tuple = new Tuple;
		tuple->ti = PB->ti;
		tuple->tj = PB->tj;
		tuple->data = PB->data;
		tuple->next = NULL;

		PA->next = tuple;
		PA = tuple;
		rear = PA;
		count++;

		PB = PB->next;
	}
}

TripleList::~TripleList()						//析构函数
{
	Tuple* temp, * PA = front;
	while (PA != NULL)
	{
		temp = PA;
		PA = PA->next;
		delete temp;
	}
	count = 0;
	front = NULL;
	rear = NULL;
}

void TripleList::append(Tuple* t)					//尾增
{
	Tuple* tuple = new Tuple;
	tuple->ti = t->ti;
	tuple->tj = t->tj;
	tuple->data = t->data;
	tuple->next = NULL;

	rear->next = tuple;
	rear = tuple;
	count++;
}

void TripleList::print() const			//打印三元表
{
	if (count == 0)
		cout << "list is empty!" << endl;
	else
	{
		Tuple* PA = front->next;
		cout << "i\tj\tdata" << endl;
		while (PA != NULL)
		{
			cout << PA->ti << "\t" << PA->tj << "\t" << PA->data << endl;
			PA = PA->next;
		}
	}
}
int TripleList::get_length() const				//获取长度
{
	return count;
}

Tuple* TripleList::get_front() const				//获得头结点
{
	return front;
}

Tuple* TripleList::get_rear() const				//获得尾结点
{
	return rear;
}

TripleList& TripleList::operator= (const TripleList& tl)	//加号运算符重载
{
	//删除原有数据
	Tuple* temp, * PA = front;
	while (PA != NULL)
	{
		temp = PA;
		PA = PA->next;
		delete temp;
	}
	count = 0;
	front = NULL;
	rear = NULL;

	//深拷贝新数据
	Tuple* tuple = new Tuple;
	tuple->next = NULL;
	front = tuple;
	rear = tuple;
	count = 0;

	Tuple* NPA = front;
	Tuple* PB = tl.get_front()->next;
	while (PB != NULL)
	{
		Tuple* tuple = new Tuple;
		tuple->ti = PB->ti;
		tuple->tj = PB->tj;
		tuple->data = PB->data;
		tuple->next = NULL;

		NPA->next = tuple;
		NPA = tuple;
		rear = NPA;
		count++;

		PB = PB->next;
	}

	return *this;
}

TripleList& TripleList::operator+ (const TripleList& tl)//加号运算符重载
{
	TripleList* C = new TripleList(tl);
	Tuple* PA;
	Tuple* PC;
	bool isappend = 1;

	for (PA = front->next; PA != NULL; PA = PA->next, isappend = 1)
	{
		for (PC = C->get_front()->next; PC != NULL; PC = PC->next)
		{
			//坐标相等，则值相加；遍历完没有相等，则 C 尾增
			if (PC->ti == PA->ti && PC->tj == PA->tj)
			{
				PC->data += PA->data;
				isappend = 0;	//为1 表示矩阵中该位置是0，三元组表需要尾增
			}
		}
		if (isappend == 1)
			C->append(PA);
	}
	return *C;
}
//TripleList& TripleList::ADD(TripleList& tl)		//三元表相加并返回为新表
//{
//	TripleList C(tl);
//	Tuple* PA;
//	Tuple* PC;
//	bool isappend = 1;
//
//	for (PA = front->next; PA != NULL; PA = PA->next, isappend = 1)
//	{
//		for (PC = C.get_front()->next; PC != NULL; PC = PC->next)
//		{
//			//坐标相等，则值相加；遍历完没有相等，则 C 尾增
//			if (PC->ti == PA->ti && PC->tj == PA->tj)
//			{
//				PC->data += PA->data;
//				isappend = 0;	//为1 表示矩阵中该位置是0，三元组表需要尾增
//			}
//		}
//		if (isappend == 1)
//			C.append(PA);
//	}
//	return C;
//}
//TripleList C(tl)这里的是C是临时变量，函数调用完会删除，会执行TripleList析构函数，使得返回的值没有意义