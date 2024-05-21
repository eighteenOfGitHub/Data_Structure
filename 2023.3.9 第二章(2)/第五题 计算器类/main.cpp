#include"Stack.hpp"
#include<string>
#include<sstream>

const int char_cal_num = 16;	//计算机符号的数量
char char_cal[char_cal_num] =	//计算机中所有需要的符号
							   {'0','1','2','3','4','5','6','7','8','9',
								'+','-','*','/',
								'(',')' };
bool calculator_have(char a)	//判断a在系统中有没有
{
	for (int i = 0; i < char_cal_num; i++)
	{
		if (a == char_cal[i])
			return true;
	}
	return false;
}

bool isrightexpression(string expression)	//判断表达式是否合法
{
	//先判断是不是每个符号是本计算机系统所包含的
	for(int i  = 0;i<expression.size();i++)
	{
		char c = expression[i];
		if (!calculator_have(c))
			return false;
	}

	//判断所需要的参数
	char first_last;
	char secend_last;
	int right_bracket_number = 0;   //右括号的数量
	int num = expression.length();	//循环次数
	
	//最后一个字符不能是左括号和运算符
	first_last = expression.back();
	if (first_last == '+' || first_last == '-' ||
		first_last == '*' || first_last == '/' || first_last == '(')
		return false;

	//判断，如果有误则返回
	for (int i = 0; i < num - 1; i++)
	{
		first_last = expression.back();
		expression.pop_back();
		secend_last = expression.back();
		
		switch (first_last)
		{
		//运算符前面必须是数字
		case '+':
		case '-':
		case '*':
		case '/':
		{
			if (secend_last!=')' && (secend_last < '0' || secend_last > '9'))
				return false;
			break;
		}
		//右括号前必须是数字
		case ')':
		{
			if (secend_last < '0' || secend_last > '9')
				return false;
			right_bracket_number += 1;
			break;
		}
		//左括号前面必须是运算符，已经有右括号（除首位的左括号）
		case '(':
		{
			if (secend_last != '+' && secend_last != '-' &&
				secend_last != '*' && secend_last != '/')
				return false;
			if (right_bracket_number == 0)
				return false;
			right_bracket_number--;
			break;
		}
		}
	}
	//最前面的字符只能是左括号或数字
	first_last = expression.back();
	if (first_last == '+' || first_last == '-' ||
		first_last == '*' || first_last == '/' ||
		first_last == ')')
		return false;
	return true;
}

string get_expression(string expression)	//将输入的表达式转化为本系统所需要的结构
{
	string cal_expression("#");
	cal_expression += expression;
	cal_expression += "#";

	return cal_expression;
}

//判断优先级
bool ispreferential(char top,char CurrentC)
{
	int preferential_val1 = 0;	//优先级用值的大小表示
	int preferential_val2 = 0;
	switch (top)
	{
	case '+':
	case '-':
		preferential_val1 = 1;
		break;
	case '*':
	case '/':
		preferential_val1 = 2;
		break;
	}
	switch (CurrentC)
	{
	case '+':
	case '-':
		preferential_val2 = 1;
		break;
	case '*':
	case '/':
		preferential_val2 = 2;
		break;
	}
	if (preferential_val1 >= preferential_val2)
		return true;
	else return false;
}

//字符串转换为整数
double StringIntInt(string CurrentS)
{
	istringstream is(CurrentS);
	int number;
	is >> number;
	return number;
}

//实现两个数之间的计算
double get_tempresult(char ope, double number1, double number2)
{
	switch (ope)
	{
	case '+': return number1 + number2; break;
	case '-': return number1 - number2; break;
	case '*': return number1 * number2; break;
	case '/': return number1 / number2; break;
	}
}

bool getresult(string expression, double& result)		//计算结果
{
	//先将字符串倒置
	reverse(expression.begin(), expression.end());
	
	//需要用到的参数
	char CurrentC = expression.back();
	string CurrentS;
	Stack<char> ope_st(10);
	Stack<double> num_st(10);
	ope_st.push(CurrentC);
	char ope;	//运算符
	double number1, number2, tempresult;
	
	//读取字符串,为#,开始运行，否则报错
	if (CurrentC == '#')
	{
		expression.pop_back();
		CurrentC = expression.back();
		while (CurrentC != '#')
		{
			//读取尾字符保存到临时字符串中，判断是数还是符号
			if ('0' <= CurrentC && CurrentC <= '9')
			{
				CurrentS += CurrentC;
				expression.pop_back();
				CurrentC = expression.back();
				//如果下一个是运算符，字符串转换为整数类型，入栈
				if (CurrentC < '0' || CurrentC > '9')
				{
					double number = StringIntInt(CurrentS);
					num_st.push(number);
					CurrentS = "";
				}
				continue;
			}
			else
			{
				if (CurrentC == '(')
				{
					ope_st.push(CurrentC);
					expression.pop_back();
					CurrentC = expression.back();
					continue;
				}	
				else if (CurrentC == ')')
				{
					//取栈顶运算符，计算
					ope_st.get_top(ope);
					ope_st.pop();
					if (ope == '(')
					{
						expression.pop_back();
						CurrentC = expression.back();
						continue;
					}
					else
					{
						num_st.get_top(number2);
						num_st.pop();
						num_st.get_top(number1);
						num_st.pop();
						tempresult = get_tempresult(ope, number1, number2);
						num_st.push(tempresult);
					}
				}
				else
				{
					//如果是运算符，判断优先级
					ope_st.get_top(ope);
					if (ispreferential(ope, CurrentC))
					{
						//如果栈顶运算符优先级大于currentS，则取出topS进行运算（运算函数）
						ope_st.pop();
						num_st.get_top(number2);
						num_st.pop();
						num_st.get_top(number1);
						num_st.pop();
						tempresult = get_tempresult(ope, number1, number2);
						num_st.push(tempresult);
					}
					else
					{
						//如果栈顶运算符优先级小于currentS,则入栈
						ope_st.push(CurrentC);
						expression.pop_back();
						CurrentC = expression.back();
					}
				}
			}
		}
		ope_st.get_top(ope);
		ope_st.pop();
		num_st.get_top(number2);
		num_st.pop();
		num_st.get_top(number1);
		num_st.pop();
		result = get_tempresult(ope, number1, number2);
		return true;
	}
	else
		return false;
}


void calculator()	//主系统
{
	cout << "请输入您所需要计算的表达式: " << endl;
	string expression;
	string cal_expression;
	while (true)		//表达式形式转换
	{
		getline(cin, expression);
		if (!isrightexpression(expression))  //检验表达式合法性
		{
			cout << "您输入的表达式有误，请重新输入: " << endl;
			continue;
		}
		else 
		{
			cal_expression = get_expression(expression);
			break;
		}
	}

	double result;
	if (getresult(cal_expression, result))
		cout << "结果为: " << result << endl;
	else
		cout << "计算错误" << endl;
}

int main()
{
	cout << "欢迎使用计算器系统！" << endl;
	//正整数四则运算
	calculator();



	return 0;
}