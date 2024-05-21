#pragma once

class SequentialSort {//À≥–Ú±Ì≈≈–Ú
public:
    static void bubbleSort(int data[], int size) {//√∞≈›≈≈–Ú
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }
    static void quickSort(int data[], int start, int end) {//øÏÀŸ≈≈–Ú
        if (start >= end) return;
        int i = start - 1, j = end + 1, x = data[(start + end) / 2];
        while (i < j)
        {
            do i++; while (data[i] < x);
            do j--; while (data[j] > x);
            if (i < j) swap(data[i], data[j]);
        }
        quickSort(data, start, j), quickSort(data, j + 1, end);
    }

    static void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
};