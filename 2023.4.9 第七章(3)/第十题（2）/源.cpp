#include<iostream>
using namespace std;
const int n = 5;
const int k = 3;

void getson(int* arr, int start, int* result, int count)//start 为变量起始位置, count 为 result 的索引值，且为还需要找多少个数
{
    for (int i = start; i < n + 1 - count; i++)     
    {
        result[count - 1] = i;  //存储值
        if (count - 1 == 0)     //到达三个时，输出
        {
            for (int j = k - 1; j >= 0; j--)
                cout << arr[result[j]] << "\t";
            cout << endl;
        }
        else
            getson(arr, i + 1, result, count - 1);
    }
}
//getson用于进入每一层
//for的结束条件作为递归的结束条件
//输出为count-1为0时，即到达最底层输出

int main()
{
    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    int arr[n];         //原数组
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int result[n];       //result保存结果，保存所需要的输出的数在原数组中的位置

    getson(arr, 0, result, k);
    return 0;
}