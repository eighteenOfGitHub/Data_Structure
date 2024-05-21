#include<iostream>
using namespace std;

void Print(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

//������A���±�Ϊs��t���ӱ���л���
void partition(int A[], int s, int t, int* cutpoint){
	int x = A[s];     //�����м�Ԫ�أ��ڳ���λ
	int i = s, j = t; //�������±�
	while (i != j) {
		while (i<j && A[j] > x)   
			j--;
		if (i < j) { 
			A[i] = A[j];  i = i + 1; 
		}
		while (i < j && A[i] < x)   
			i++;
		if (i < j) { 
			A[j] = A[i];   j = j - 1; 
		}
	}
	A[i] = x;  
	*cutpoint = i;
}

//������A���±��s��t��Ԫ����ɵ��ӱ��������
void Quick_sort(int A[], int s, int t) {
	if (s < t) {
		int* i = new int(0);
		partition(A, s, t, i);		//����
		
		cout << "�������� �� " << s << " �� " << t << " :" << endl;
		Print(A, 16);

		Quick_sort(A, s, *i - 1);	//��ǰ���ӱ��������
		Quick_sort(A, *i + 1, t);	//�Ժ����ӱ��������
	}
}

void test(){
	int A[16] = { 50, 30, 120, 25, 85, 40, 100, 12, 90, 15, 60, 35, 105, 78, 10, 28};
	Quick_sort(A, 0, 15);
}

int main(){
	test();
	return 0;
}
