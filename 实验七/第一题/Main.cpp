#include <iostream>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include"SequentialSearch.h"
#include"AvlTree.h"
#include"HashTableSearch.h"
using namespace std;


int* generateRandomData(int size) {
    int* data = new int[size];
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        data[i] = rand() % size;
    }
    return data;
}

int main() {

    const int N = 10000;
    int* data = generateRandomData(N);
    int target = data[N / 2];

    //˳������
    auto start = chrono::steady_clock::now();
    int index = SequentialSearch::linearSearch(data, N, target);
    auto end = chrono::steady_clock::now();
    chrono::duration<double, milli> linearSearchTime = end - start;

    if (index != -1) {
        cout << "˳�����ҽ����" << index << endl;
    }
    else {
        cout << "δ�ҵ�Ŀ��ֵ" << endl;
    }
    cout << "˳�����Һ�ʱ��" << linearSearchTime.count() << " ms" << endl;


    //�������
    AvlTree tree;
    tree.Insert(data);
    start = chrono::steady_clock::now();
    AvlNode* result = tree.binarySearchTree(target);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> binarySearchTreeTime = end - start;

    if (result != NULL) {
        cout << "������ҽ����" << result->data<< endl;
    }
    else {
        cout << "δ�ҵ�Ŀ��ֵ" << endl;
    }
    cout << "������Һ�ʱ��" << binarySearchTreeTime.count() << " ms" << endl;


    //��ϣ��1����
    HashTableSearchBy10000 hashTable;
    for (int i = 0; i < N; i++) {
        hashTable.insert(data[i], i);
    }
    start = chrono::steady_clock::now();
    int hashTableResult = hashTable.search(target);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> hashTableSearchTime = end - start;

    if (hashTableResult != -1) {
        cout << "ɢ�б���ҽ����" << hashTableResult << endl;
    }
    else {
        cout << "δ�ҵ�Ŀ��ֵ" << endl;
    }
    cout << "ɢ�б���Һ�ʱ��" << hashTableSearchTime.count() << " ms" << endl;

    //��ϣ��2����
    HashTableSearchBy100 hashTable2;
    for (int i = 0; i < N; i++) {
        hashTable2.insert(data[i], i);
    }
    start = chrono::steady_clock::now();
    int hashTableResult2 = hashTable2.search(target);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> hashTableSearchTime2 = end - start;

    if (hashTableResult2 != -1) {
        cout << "ɢ�б���ҽ����" << hashTableResult2 << endl;
    }
    else {
        cout << "δ�ҵ�Ŀ��ֵ" << endl;
    }
    cout << "ɢ�б���Һ�ʱ��" << hashTableSearchTime2.count() << " ms" << endl;

    delete[] data;

    return 0;
}