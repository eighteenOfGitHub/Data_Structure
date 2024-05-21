#pragma once
class BinaryTreeSort {
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
    };

public:
    static void heapify(int data[], int size, int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && data[left] > data[largest]) {
            largest = left;
        }

        if (right < size && data[right] > data[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(data[index], data[largest]);
            heapify(data, size, largest);
        }
    }

    static void heapSort(int data[], int size) {//堆排序
        for (int i = size / 2 - 1; i >= 0; i--) {   //从下往上调整
            heapify(data, size, i);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(data[0], data[i]);
            heapify(data, i, 0);
        }
    }

    static void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
};