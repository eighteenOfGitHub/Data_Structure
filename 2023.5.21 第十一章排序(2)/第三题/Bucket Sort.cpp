#include<iostream>
#include"Queue.h"
using namespace std;

void Print(int A[], int n){
	for (int i = 0; i < n; i++){
		cout << A[i] << " ";
	}
	cout << endl;
}

void Bucket_Sort(int A[], int n){
	Queue queue0;
	Queue queue1;
	Queue queue2;
	for (int i = 0; i < n; i++){
		if (A[i] % 3 == 0)queue0.append(A[i]);
		else if (A[i] % 3 == 1)queue1.append(A[i]);
		else queue2.append(A[i]);
	}
	int index = 0;
	while (queue0.get_front(A[index])) {
		queue0.serve();
		index++;
	}
	while (queue1.get_front(A[index])) {
		queue1.serve();
		index++;
	}
	while (queue2.get_front(A[index])) {
		queue2.serve();
		index++;
	}
}

void test1(){
	int A[10] = { 46,1,2,3,4,5,6,7,8,9 };
	cout << "46,1,2,3,4,5,6,7,8,9" << endl;
	Bucket_Sort(A, 10);
	Print(A, 10);
	cout << endl;
}

void test2() {
	int A[10] = { 0,1,2,74,4,5,6,45,8,9 };
	cout << "0,1,2,74,4,5,6,45,8,9" << endl;
 	Bucket_Sort(A, 10);
	Print(A, 10);
	cout << endl;
}

void test3() {
	int A[9] = { 1,2,3,4,5,45,7,8,66 };
	cout << "1,2,3,4,5,45,7,8,66" << endl;
	Bucket_Sort(A,9);
	Print(A, 9);
	cout << endl;
}

int main(){
	test1();
	test2();
	test3();
	return 0;
}