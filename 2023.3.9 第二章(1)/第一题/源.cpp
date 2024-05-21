#include<iostream>
#include"Stack.hpp"
#include"Queue.hpp"
using namespace std;

template<class T>
void in(Queue<T> input, Stack<T> temp, Queue<T> output);
template<class T>
void out(Queue<T> input, Stack<T> temp, Queue<T> output);
template<class T>

void func(Queue<T> input, Stack<T> temp, Queue<T> output)
{
	static int judge = 0;

	//�ж�ջ����input�ӿ�ʱ�����output������
	if (input.empty() && temp.empty())
	{
		T element;
		while (!output.empty())
		{
			output.get_front(element);
			cout << element; 
			output.serve();
		}
		cout << " ";
		++judge;
		if (judge == 5)
		{
			cout << endl;
			judge = 0;
		}
		cout << endl;
		return;
	}

	//pattern == in, ȡ��inputԪ�أ����뵽tempջ��
//pattern ==out, ȡ��tempԪ�أ�����output������
	in(input, temp, output);
	out(input, temp, output);
}

template<class T>
void in(Queue<T> input, Stack<T> temp, Queue<T> output)
{
	if (input.empty())
		return;
	T element;
	input.get_front(element);		//ȡ������Ԫ��
	input.serve();					//ɾ��ͷԪ��
	temp.push(element);				//ѹջ

	func(input, temp, output);		//���빦��ѡ��
}

template<class T>
void out(Queue<T> input, Stack<T> temp, Queue<T> output)
{
	if (temp.empty())
		return;
	T element;
	temp.get_top(element);
	temp.pop();
	output.append(element);

	func(input, temp, output);
}

int main(){
	cout << "���������鳤�ȣ�";
	int n;
	cin >> n;

	Queue<int> input;
	Stack<int> temp(n);
	Queue<int> output;

	cout << "���������飺";
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		input.append(num);
	}

	func(input, temp, output);

	return 0;
}