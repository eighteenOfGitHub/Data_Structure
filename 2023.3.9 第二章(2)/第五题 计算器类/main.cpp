#include"Stack.hpp"
#include<string>
#include<sstream>

const int char_cal_num = 16;	//��������ŵ�����
char char_cal[char_cal_num] =	//�������������Ҫ�ķ���
							   {'0','1','2','3','4','5','6','7','8','9',
								'+','-','*','/',
								'(',')' };
bool calculator_have(char a)	//�ж�a��ϵͳ����û��
{
	for (int i = 0; i < char_cal_num; i++)
	{
		if (a == char_cal[i])
			return true;
	}
	return false;
}

bool isrightexpression(string expression)	//�жϱ��ʽ�Ƿ�Ϸ�
{
	//���ж��ǲ���ÿ�������Ǳ������ϵͳ��������
	for(int i  = 0;i<expression.size();i++)
	{
		char c = expression[i];
		if (!calculator_have(c))
			return false;
	}

	//�ж�����Ҫ�Ĳ���
	char first_last;
	char secend_last;
	int right_bracket_number = 0;   //�����ŵ�����
	int num = expression.length();	//ѭ������
	
	//���һ���ַ������������ź������
	first_last = expression.back();
	if (first_last == '+' || first_last == '-' ||
		first_last == '*' || first_last == '/' || first_last == '(')
		return false;

	//�жϣ���������򷵻�
	for (int i = 0; i < num - 1; i++)
	{
		first_last = expression.back();
		expression.pop_back();
		secend_last = expression.back();
		
		switch (first_last)
		{
		//�����ǰ�����������
		case '+':
		case '-':
		case '*':
		case '/':
		{
			if (secend_last!=')' && (secend_last < '0' || secend_last > '9'))
				return false;
			break;
		}
		//������ǰ����������
		case ')':
		{
			if (secend_last < '0' || secend_last > '9')
				return false;
			right_bracket_number += 1;
			break;
		}
		//������ǰ���������������Ѿ��������ţ�����λ�������ţ�
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
	//��ǰ����ַ�ֻ���������Ż�����
	first_last = expression.back();
	if (first_last == '+' || first_last == '-' ||
		first_last == '*' || first_last == '/' ||
		first_last == ')')
		return false;
	return true;
}

string get_expression(string expression)	//������ı��ʽת��Ϊ��ϵͳ����Ҫ�Ľṹ
{
	string cal_expression("#");
	cal_expression += expression;
	cal_expression += "#";

	return cal_expression;
}

//�ж����ȼ�
bool ispreferential(char top,char CurrentC)
{
	int preferential_val1 = 0;	//���ȼ���ֵ�Ĵ�С��ʾ
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

//�ַ���ת��Ϊ����
double StringIntInt(string CurrentS)
{
	istringstream is(CurrentS);
	int number;
	is >> number;
	return number;
}

//ʵ��������֮��ļ���
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

bool getresult(string expression, double& result)		//������
{
	//�Ƚ��ַ�������
	reverse(expression.begin(), expression.end());
	
	//��Ҫ�õ��Ĳ���
	char CurrentC = expression.back();
	string CurrentS;
	Stack<char> ope_st(10);
	Stack<double> num_st(10);
	ope_st.push(CurrentC);
	char ope;	//�����
	double number1, number2, tempresult;
	
	//��ȡ�ַ���,Ϊ#,��ʼ���У����򱨴�
	if (CurrentC == '#')
	{
		expression.pop_back();
		CurrentC = expression.back();
		while (CurrentC != '#')
		{
			//��ȡβ�ַ����浽��ʱ�ַ����У��ж��������Ƿ���
			if ('0' <= CurrentC && CurrentC <= '9')
			{
				CurrentS += CurrentC;
				expression.pop_back();
				CurrentC = expression.back();
				//�����һ������������ַ���ת��Ϊ�������ͣ���ջ
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
					//ȡջ�������������
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
					//�������������ж����ȼ�
					ope_st.get_top(ope);
					if (ispreferential(ope, CurrentC))
					{
						//���ջ����������ȼ�����currentS����ȡ��topS�������㣨���㺯����
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
						//���ջ����������ȼ�С��currentS,����ջ
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


void calculator()	//��ϵͳ
{
	cout << "������������Ҫ����ı��ʽ: " << endl;
	string expression;
	string cal_expression;
	while (true)		//���ʽ��ʽת��
	{
		getline(cin, expression);
		if (!isrightexpression(expression))  //������ʽ�Ϸ���
		{
			cout << "������ı��ʽ��������������: " << endl;
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
		cout << "���Ϊ: " << result << endl;
	else
		cout << "�������" << endl;
}

int main()
{
	cout << "��ӭʹ�ü�����ϵͳ��" << endl;
	//��������������
	calculator();



	return 0;
}