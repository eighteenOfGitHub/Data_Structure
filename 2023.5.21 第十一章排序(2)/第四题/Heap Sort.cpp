#include<iostream>
using namespace std;

//---------------------------工具包------------------

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
//-------------------------大根堆调整----------------------------
void adjust_big(int A[], int n, int i, bool& left, bool& right) {
	if (2 * i > n) {	//左孩子为空
		return;
	}
	else {
		if (2 * i + 1 > n) {	//右孩子为空，左孩子不空
			if (A[2 * i] > A[i]) {
				int temp = A[2 * i];
				A[2 * i] = A[i];
				A[i] = temp;
				left = 1;
			}
		}
		else {	//左右孩子都不空
			if (A[i] >= A[2 * i] && A[i] >= A[2 * i + 1]) {	//根最大
				return;
			}
			else if (A[2 * i] >= A[2 * i + 1]) {	//左孩子最大
				swap(A[i], A[2 * i]);
				left = 1;
			}
			else {	//右孩子最大
				swap(A[i], A[2 * i + 1]);
				right = 1;
			}
		}
	}
}

void traversal_big(int A[], int n,int i) {
		bool left = 0, right = 0;	//判断左右孩子是否被调整，0为未调整，1为已被调整，被调整的话则以此为根重新调整
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

//-------------------------小根堆调整----------------------------
void adjust_small(int A[], int n, int i, bool& left, bool& right) {
	if (2 * i > n) {	//左孩子为空
		return;
	}
	else {
		if (2 * i + 1 > n) {	//右孩子为空，左孩子不空
			if (A[2 * i] > A[i]) {
				int temp = A[2 * i];
				A[2 * i] = A[i];
				A[i] = temp;
				left = 1;
			}
		}
		else {	//左右孩子都不空
			if (A[i] <= A[2 * i] && A[i] <= A[2 * i + 1]) {	//根最小
				return;
			}
			else if (A[2 * i] <= A[2 * i + 1]) {	//左孩子最小
				swap(A[i], A[2 * i]);
				left = 1;
			}
			else {	//右孩子最小
				swap(A[i], A[2 * i + 1]);
				right = 1;
			}
		}
	}
}

void traversal_small(int A[], int n, int i) {
	bool left = 0, right = 0;	//判断左右孩子是否被调整，0为未调整，1为已被调整，被调整的话则以此为根重新调整
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
	cout << "大根堆：";
	Print(A, 16);
	heap_sort_small(A, 16);
	cout << "小根堆：";
	Print(A, 16);

	cout << "B:" << endl;
	int B[16] = { 0,12,15,30,80,100,46,78,33,90,86,64,55,120,230,45 };
	Print(B, 15);
	heap_sort_big(B,15);
	cout << "大根堆：";
	Print(B, 15);
	heap_sort_small(B, 15);
	cout << "小根堆：";
	Print(B, 15);
}


int main() {
	test();
	return 0;
}