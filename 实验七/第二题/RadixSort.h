#pragma once
class RadixSort {//链式基数排序
private:
    struct ListNode {
        int data;
        ListNode* next;

        ListNode(int value) : data(value), next(nullptr) {}
    };

public:
    static int getMax(int data[], int size) {
        int max = data[0];
        for (int i = 1; i < size; i++) {
            if (data[i] > max) {
                max = data[i];
            }
        }
        return max;
    }

    static void countingSort(int data[], int size, int exp) {
        int* output = new int[size];
        int count[10] = { 0 };

        //统计数量
        for (int i = 0; i < size; i++) {
            count[(data[i] / exp) % 10]++;
        }

        //标记序号
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        //放入桶中
        for (int i = size - 1; i >= 0; i--) {
            output[count[(data[i] / exp) % 10] - 1] = data[i];
            count[(data[i] / exp) % 10]--;
        }
        
        //输出
        for (int i = 0; i < size; i++) {
            data[i] = output[i];
        }

        delete[] output;
    }

    static void radixSort(int data[], int size) {
        int max = getMax(data, size);

        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(data, size, exp);
        }
    }
};