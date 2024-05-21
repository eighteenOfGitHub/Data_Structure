#pragma once
#include<iostream>
using namespace std;

class SequentialSearch {//顺序表查找
public:
    static int linearSearch(int data[], int size, int target) {
        for (int i = 0; i < size; i++) {
            if (data[i] == target) {
                return i;
            }
        }
        return -1;  // 未找到目标值
    }
};
