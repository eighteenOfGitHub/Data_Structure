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

    //顺序表查找
    auto start = chrono::steady_clock::now();
    int index = SequentialSearch::linearSearch(data, N, target);
    auto end = chrono::steady_clock::now();
    chrono::duration<double, milli> linearSearchTime = end - start;

    if (index != -1) {
        cout << "顺序表查找结果：" << index << endl;
    }
    else {
        cout << "未找到目标值" << endl;
    }
    cout << "顺序表查找耗时：" << linearSearchTime.count() << " ms" << endl;


    //树表查找
    AvlTree tree;
    tree.Insert(data);
    start = chrono::steady_clock::now();
    AvlNode* result = tree.binarySearchTree(target);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> binarySearchTreeTime = end - start;

    if (result != NULL) {
        cout << "树表查找结果：" << result->data<< endl;
    }
    else {
        cout << "未找到目标值" << endl;
    }
    cout << "树表查找耗时：" << binarySearchTreeTime.count() << " ms" << endl;


    //哈希表1查找
    HashTableSearchBy10000 hashTable;
    for (int i = 0; i < N; i++) {
        hashTable.insert(data[i], i);
    }
    start = chrono::steady_clock::now();
    int hashTableResult = hashTable.search(target);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> hashTableSearchTime = end - start;

    if (hashTableResult != -1) {
        cout << "散列表查找结果：" << hashTableResult << endl;
    }
    else {
        cout << "未找到目标值" << endl;
    }
    cout << "散列表查找耗时：" << hashTableSearchTime.count() << " ms" << endl;

    //哈希表2查找
    HashTableSearchBy100 hashTable2;
    for (int i = 0; i < N; i++) {
        hashTable2.insert(data[i], i);
    }
    start = chrono::steady_clock::now();
    int hashTableResult2 = hashTable2.search(target);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> hashTableSearchTime2 = end - start;

    if (hashTableResult2 != -1) {
        cout << "散列表查找结果：" << hashTableResult2 << endl;
    }
    else {
        cout << "未找到目标值" << endl;
    }
    cout << "散列表查找耗时：" << hashTableSearchTime2.count() << " ms" << endl;

    delete[] data;

    return 0;
}