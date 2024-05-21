#include <iostream>
#include <ctime>
#include <chrono>
#include"SequentialSort.h"
#include"BinaryTreeSort.h"
#include"RadixSort.h"

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

    //ð������
    int* dataCopy1 = new int[N];
    copy(data, data + N, dataCopy1);
    auto start = chrono::steady_clock::now();
    SequentialSort::bubbleSort(dataCopy1, N);
    auto end = chrono::steady_clock::now();
    chrono::duration<double, milli> bubbleSortTime = end - start;


    //��������
    int* dataCopy2 = new int[N];
    copy(data, data + N, dataCopy2);
    start = chrono::steady_clock::now();
    SequentialSort::quickSort(dataCopy2, 0,N-1);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> quickSortTime = end - start;

    //���������
    int* dataCopy3 = new int[N];
    copy(data, data + N, dataCopy3);
    start = chrono::steady_clock::now();
    BinaryTreeSort::heapSort(dataCopy3, N);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> heapSortTime = end - start;

    //��ʽ��������
    int* dataCopy4 = new int[N];
    copy(data, data + N, dataCopy4);
    start = chrono::steady_clock::now();
    RadixSort::radixSort(dataCopy4, N);
    end = chrono::steady_clock::now();
    chrono::duration<double, milli> radixSortTime = end - start;

    cout << "ð�����������ʱ��" << bubbleSortTime.count() << " ms" << endl;
    cout << "���������ʱ��" << quickSortTime.count() << " ms" << endl;
    cout << "�������ʱ��" << heapSortTime.count() << " ms" << endl;
    cout << "��ʽ���������ʱ��" << radixSortTime.count() << " ms" << endl;

    for (int i = 0; i < N; i++) {
        cout << dataCopy2[i] << " ";
    }

    delete[] data;
    delete[] dataCopy1;
    delete[] dataCopy2;
    delete[] dataCopy3;
    delete[] dataCopy4;

    return 0;
}