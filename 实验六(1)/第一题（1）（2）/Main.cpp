#include<iostream>
#include"Graph.h"
using namespace std;

void test1() {
	cout << "test1:" << endl;

	Graph garph;
	for (int i = 0; i < 9; i++) {
		garph.insert(i);
	}

	garph.connect(0, 1);
	garph.connect(0, 2);
	garph.connect(0, 3);
	garph.connect(1, 4);
	garph.connect(1, 5);
	garph.connect(2, 6);
	garph.connect(2, 7);
	garph.connect(3, 8);

	cout << "������" << garph.getEdgeCount() << endl;
	if (garph.isTree()) {
		cout << "��һ����" << endl;
	}
	else {
		cout << "����һ����" << endl;
	}
}

void test2() {
	cout << "test2:" << endl;

	Graph garph;
	for (int i = 0; i < 9; i++) {
		garph.insert(i);
	}

	garph.connect(0, 1);
	garph.connect(0, 2);
	garph.connect(0, 3);
	garph.connect(1, 4);
	garph.connect(1, 5);
	garph.connect(2, 6);
	garph.connect(2, 7);
	garph.connect(3, 8);
	garph.connect(0, 8);

	cout << "������" << garph.getEdgeCount() << endl;
	if (garph.isTree()) {
		cout << "��һ����" << endl;
	}
	else {
		cout << "����һ����" << endl;
	}
}

int main() {
	test1();
	test2();
	return 0;
}