#include"Stack.h"
const int MAX = 100;
static int count = 0;

void findson1(Stack& stack, int n, int k, int i);//�洢��Ҫ���Ԫ�ص�ջ ԭ����Ԫ�ظ��� ѡȡԪ�ظ��� �α굱ǰλ��
void findson2(Stack& stack, int n, int k, int i);//�洢��Ҫ���Ԫ�ص�ջ ԭ����Ԫ�ظ��� ѡȡԪ�ظ��� �α굱ǰλ��

void findson2(Stack& stack, int n, int k, int i)//�洢��Ҫ���Ԫ�ص�ջ ԭ����Ԫ�ظ��� ѡȡԪ�ظ��� �α굱ǰλ��
{
	if (stack.Empty() && n - i + 1 < k)return;
	stack.Push(i);
	findson1(stack, n, k, i + 1);
}

void findson1(Stack &stack, int n, int k, int i)//�洢��Ҫ���Ԫ�ص�ջ ԭ����Ԫ�ظ��� ѡȡԪ�ظ��� �α굱ǰλ��
{
	if (stack.get_count() != k)
	{
		stack.Push(i);
		findson1(stack, n, k, i + 1);
	}
	else
	{
		stack.Invert_Print(stack.get_top());
		cout << endl;
		stack.Pop();
		if (i != n)
			findson1(stack, n, k, i + 1);
		else
		{
			i = stack.get_top()->_next->_data;
			stack.Pop();
			findson2(stack, n, k, i + 1);
		}
	}
	//	stack.Push(i);
	//	stack.Invert_Print(stack.get_top());
	//	cout << endl;
	//	stack.Pop();
	//	i = stack.get_top()->_next->_data;
	//	stack.Pop();	
	//	findson(stack, n, k, i + 1);
}

void test01()
{
	int  n, k;
	Stack stack;
	cout << "please input n(0<n<100) and k(<n):";
	cin >> n >> k;
	findson1(stack, n, k, 1);
}

void test02()
{
	Stack stack;
	stack.Invert_Print(stack.get_top());
	for (int i = 1; i <= 10; i++)
		stack.Push(i);
	stack.Invert_Print(stack.get_top());
}

int main()
{
	test01();
	//test02();
	return 0;
}