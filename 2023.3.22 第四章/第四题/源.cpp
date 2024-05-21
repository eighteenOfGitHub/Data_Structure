#include"List.hpp"
#include"Stack.hpp"
int main()
{
	List<int> list1;
	List<int> list2;
	Stack<int> stack;
	List<int> list;

	//��ʼ������һ
	for (int i = 0; i < 10; i += 2)
		list1.append(i);
	cout << "list1: ";
	for (int x = 0, int i = 1; i <= list1.length(); i++)
	{
		list1.get_element(i, x);
		cout << x << " ";
	}
	cout << endl;

	//��ʼ�������
	for (int i = 1; i < 10; i += 2)
		list2.append(i);
	cout << "list2: ";
	for (int x = 0, int i = 1; i <= list2.length(); i++)
	{
		list1.get_element(i, x);
		cout << x << " ";
	}
	cout << endl;

	//�ϲ�����һ�������
	int num1 = 1, num2 = 1, x1, x2, y;
	while (num1 > list1.length() || num2 > list2.length())
	{
		list1.get_element(num1, x1);
		list2.get_element(num2, x2);

		y = (x1 > x2) ? x1 : x2;
		(x1 > x2) ? (num1++) : (num2++);

		stack.push(y);
	}
	//һ����������ɺ󣬽���һ������ʣ���Ԫ�ط���ջ��
	if (num1 > list1.length())
	{
		for (; num2 <= list2.length(); num2++)
		{
			list2.get_element(num2, x2);
			y = x2;
			stack.push(y);
		}
	}
	else
	{
		for (; num1 <= list1.length(); num1++)
		{
			list1.get_element(num1, x1);
			y = x1;
			stack.push(y);
		}
	}

	//�������������
	int temp;
	for (int i = 0; i < stack.length(); i++)
	{
		stack.get_top(temp);
		list.append(temp);
	}
	cout << "list: ";
	for (int x = 0, int i = 1; i <= list.length(); i++)
	{
		list1.get_element(i, x);
		cout << x << " ";
	}
	cout << endl;

	return 0;
}
