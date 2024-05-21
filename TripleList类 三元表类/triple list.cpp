#include"triple list.h"
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

void TripleList::append(Tuple* t)					//β��
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
			cout << PA->ti << "\t" << PA->tj << "\t" << PA->data << endl;
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
			}
		}
		if (isappend == 1)
			C->append(PA);
	}
	return *C;
}
//TripleList& TripleList::ADD(TripleList& tl)		//��Ԫ����Ӳ�����Ϊ�±�
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
//			//������ȣ���ֵ��ӣ�������û����ȣ��� C β��
//			if (PC->ti == PA->ti && PC->tj == PA->tj)
//			{
//				PC->data += PA->data;
//				isappend = 0;	//Ϊ1 ��ʾ�����и�λ����0����Ԫ�����Ҫβ��
//			}
//		}
//		if (isappend == 1)
//			C.append(PA);
//	}
//	return C;
//}
//TripleList C(tl)�������C����ʱ�����������������ɾ������ִ��TripleList����������ʹ�÷��ص�ֵû������