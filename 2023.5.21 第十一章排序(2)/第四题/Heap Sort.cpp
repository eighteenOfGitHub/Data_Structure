#include<iostream>
using namespace std;

//---------------------------���߰�------------------

void Print(int A[], int n) {
	for (int i = 1; i <= n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//-------------------------����ѵ���----------------------------
void adjust_big(int A[], int n, int i, bool& left, bool& right) {
	if (2 * i > n) {	//����Ϊ��
		return;
	}
	else {
		if (2 * i + 1 > n) {	//�Һ���Ϊ�գ����Ӳ���
			if (A[2 * i] > A[i]) {
				int temp = A[2 * i];
				A[2 * i] = A[i];
				A[i] = temp;
				left = 1;
			}
		}
		else {	//���Һ��Ӷ�����
			if (A[i] >= A[2 * i] && A[i] >= A[2 * i + 1]) {	//�����
				return;
			}
			else if (A[2 * i] >= A[2 * i + 1]) {	//�������
				swap(A[i], A[2 * i]);
				left = 1;
			}
			else {	//�Һ������
				swap(A[i], A[2 * i + 1]);
				right = 1;
			}
		}
	}
}

void traversal_big(int A[], int n,int i) {
		bool left = 0, right = 0;	//�ж����Һ����Ƿ񱻵�����0Ϊδ������1Ϊ�ѱ��������������Ļ����Դ�Ϊ�����µ���
		adjust_big(A, n, i,left,right);
		if (left == 1) traversal_big(A, n, i * 2);
		if (right == 1) traversal_big(A, n, i * 2 + 1);

}

void heap_sort_big(int A[], int n) {
	int i = n / 2 ;
	for (; i > 0; i--) {
		traversal_big(A, n, i);
	}
}

//-------------------------С���ѵ���----------------------------
void adjust_small(int A[], int n, int i, bool& left, bool& right) {
	if (2 * i > n) {	//����Ϊ��
		return;
	}
	else {
		if (2 * i + 1 > n) {	//�Һ���Ϊ�գ����Ӳ���
			if (A[2 * i] > A[i]) {
				int temp = A[2 * i];
				A[2 * i] = A[i];
				A[i] = temp;
				left = 1;
			}
		}
		else {	//���Һ��Ӷ�����
			if (A[i] <= A[2 * i] && A[i] <= A[2 * i + 1]) {	//����С
				return;
			}
			else if (A[2 * i] <= A[2 * i + 1]) {	//������С
				swap(A[i], A[2 * i]);
				left = 1;
			}
			else {	//�Һ�����С
				swap(A[i], A[2 * i + 1]);
				right = 1;
			}
		}
	}
}

void traversal_small(int A[], int n, int i) {
	bool left = 0, right = 0;	//�ж����Һ����Ƿ񱻵�����0Ϊδ������1Ϊ�ѱ��������������Ļ����Դ�Ϊ�����µ���
	adjust_small(A, n, i, left, right);
	if (left == 1) traversal_small(A, n, i * 2);
	if (right == 1) traversal_small(A, n, i * 2 + 1);

}

void heap_sort_small(int A[], int n) {
	int i = n / 2;
	for (; i > 0; i--) {
		traversal_small(A, n, i);
	}
}

void test() {

	cout << "A:" << endl;
	int A[17] = {0, 50, 30, 120, 25, 85, 40, 100, 12, 90, 15, 60, 35, 105, 78, 10, 28 };
	Print(A, 16);
	heap_sort_big(A, 16);
	cout << "����ѣ�";
	Print(A, 16);
	heap_sort_small(A, 16);
	cout << "С���ѣ�";
	Print(A, 16);

	cout << "B:" << endl;
	int B[16] = { 0,12,15,30,80,100,46,78,33,90,86,64,55,120,230,45 };
	Print(B, 15);
	heap_sort_big(B,15);
	cout << "����ѣ�";
	Print(B, 15);
	heap_sort_small(B, 15);
	cout << "С���ѣ�";
	Print(B, 15);
}


int main() {
	test();
	return 0;
}