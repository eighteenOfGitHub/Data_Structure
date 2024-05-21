#include"triple list.h"
//--------------------------------TripleList����������-------------------------

TripleList::TripleList()
{
	Tuple* tuple = new Tuple;
	tuple->next = NULL;
	front = tuple;
	rear = tuple;
	count = 0;
}

TripleList::TripleList(int A[][MAX])	//��Ԫ���캯��
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

TripleList::TripleList(TripleList& tl)			//��Ԫ��������
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

TripleList::TripleList(const TripleList& tl)			//��Ԫ��������
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

TripleList::~TripleList()						//��������
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

//--------------------------------TripleList���߰�-------------------------

void TripleList::append(Tuple* t)					//β��
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
	if (count == 0) {	//��Ϊ��
		ptr->next = tuple;
		rear = tuple;
		count++;
		return;
	}
	if (t->ti < ptr->next->ti || (t->ti == ptr->next->ti && t->tj < ptr->next->tj)) {	//��Ϊ�գ���ȥ��һ���Ϳ��Բ��������
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

void TripleList::print() const			//��ӡ��Ԫ��
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
int TripleList::get_length() const				//��ȡ����
{
	return count;
}

Tuple* TripleList::get_front() const				//���ͷ���
{
	return front;
}

Tuple* TripleList::get_rear() const				//���β���
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
//--------------------------------TripleList�㷨-------------------------

TripleList& TripleList::operator= (const TripleList& tl)	//�Ӻ����������
{
	//ɾ��ԭ������
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

	//���������
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

TripleList& TripleList::operator+ (const TripleList& tl)//�Ӻ����������
{
	TripleList* C = new TripleList(tl);
	Tuple* PA;
	Tuple* PC;
	bool isappend = 1;

	for (PA = front->next; PA != NULL; PA = PA->next, isappend = 1)
	{
		for (PC = C->get_front()->next; PC != NULL; PC = PC->next)
		{
			//������ȣ���ֵ��ӣ�������û����ȣ��� C β��
			if (PC->ti == PA->ti && PC->tj == PA->tj)
			{
				PC->data += PA->data;
				isappend = 0;	//Ϊ1 ��ʾ�����и�λ����0����Ԫ�����Ҫβ��
				break;
			}
		}
		if (isappend == 1)
			C->insert(PA);
	}
	return *C;
}

TripleList& TripleList::operator* (const TripleList& tl)	//�˺����������
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