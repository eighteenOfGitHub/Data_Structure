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

	//判断栈空且input队空时，输出output的数据
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

	//pattern == in, 取出input元素，放入到temp栈中
//pattern ==out, 取出temp元素，放入output队列中
	in(input, temp, output);
	out(input, temp, output);
}

template<class T>
void in(Queue<T> input, Stack<T> temp, Queue<T> output)
{
	if (input.empty())
		return;
	T element;
	input.get_front(element);		//取队列首元素
	input.serve();					//删除头元素
	temp.push(element);				//压栈

	func(input, temp, output);		//进入功能选择
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
	cout << "请输入数组长度：";
	int n;
	cin >> n;

	Queue<int> input;
	Stack<int> temp(n);
	Queue<int> output;

	cout << "请输入数组：";
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		input.append(num);
	}

	func(input, temp, output);

	return 0;
}