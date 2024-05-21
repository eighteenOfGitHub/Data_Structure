#include"triple list.h"
//--------------------------------TripleList构造与析构-------------------------

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
				Tuple* tuple = new Tuple(i,j,A[i][j]);

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
		Tuple* tuple = new Tuple(PB);

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
		Tuple* tuple = new Tuple(PB);

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

//--------------------------------TripleList工具包-------------------------

void TripleList::append(Tuple* t)					//尾增
{
	Tuple* tuple = new Tuple(t);

	rear->next = tuple;
	rear = tuple;
	count++;
}

void TripleList::insert(Tuple* t)
{
	Tuple* tuple = new Tuple(t);
	Tuple* ptr = front;
	if (count == 0) {	//表为空
		ptr->next = tuple;
		rear = tuple;
		count++;
		return;
	}
	if (t->ti < ptr->next->ti || (t->ti == ptr->next->ti && t->tj < ptr->next->tj)) {	//表不为空，除去第一个就可以插入的特例
		tuple->next = ptr->next;
		ptr->next = tuple;
		count++;
		return;
	}
	ptr = ptr->next;
	while (ptr->next != NULL) {
		if (ptr->next != NULL && ptr->ti == t->ti) {
			while (ptr->next != NULL && t->ti == ptr->next->ti && t->tj < ptr->next->tj) {
				ptr = ptr->next;
			}
			if (ptr->next == NULL) {
				ptr->next = tuple;
				rear = tuple;
				count++;
				return;
			}
			else if (t->ti > ptr->ti && t->ti == ptr->next->ti && t->tj > ptr->next->tj) {
				ptr = ptr->next;
			}
			else {
				tuple->next = ptr->next;
				ptr->next = tuple;
				count++;
				return;
			}
		}
		else {
			if (ptr->next != NULL && t->ti == ptr->next->ti && t->tj < ptr->next->tj) {
				tuple->next = ptr->next;
				ptr->next = tuple;
				count++;
				return;
			}
			ptr = ptr->next;
		}
	}
	if (ptr->next == NULL) {
		ptr->next = tuple;
		rear = tuple;
		count++;
		return;
	}
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
			cout << PA->ti + 1 << "\t" << PA->tj + 1 << "\t" << PA->data << endl;
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
int TripleList::getValue(int i, int j) const
{
	int value = 0;
	Tuple* ptr = front->next;
	for (; ptr != NULL; ptr = ptr->next) {
		if (i == ptr->ti && j == ptr->tj) {
			return ptr->data;
		}
	}
	return 0;
}
//--------------------------------TripleList算法-------------------------

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
		Tuple* tuple = new Tuple(PB);

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
				break;
			}
		}
		if (isappend == 1)
			C->insert(PA);
	}
	return *C;
}

TripleList& TripleList::operator* (const TripleList& tl)	//乘号运算符重载
{
	TripleList* tlist = new TripleList();
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			int value = 0;
			for (int a = 0; a < MAX; a++) {
				value += getValue(i, a) * tl.getValue(a, j);
			}
			if (value != 0) {
				Tuple* tuple = new Tuple(i, j, value);
				tlist->append(tuple);
			}
		}
	}
	return *tlist;
}