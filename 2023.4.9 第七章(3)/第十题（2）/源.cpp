#include<iostream>
using namespace std;
const int n = 5;
const int k = 3;

void getson(int* arr, int start, int* result, int count)//start Ϊ������ʼλ��, count Ϊ result ������ֵ����Ϊ����Ҫ�Ҷ��ٸ���
{
    for (int i = start; i < n + 1 - count; i++)     
    {
        result[count - 1] = i;  //�洢ֵ
        if (count - 1 == 0)     //��������ʱ�����
        {
            for (int j = k - 1; j >= 0; j--)
                cout << arr[result[j]] << "\t";
            cout << endl;
        }
        else
            getson(arr, i + 1, result, count - 1);
    }
}
//getson���ڽ���ÿһ��
//for�Ľ���������Ϊ�ݹ�Ľ�������
//���Ϊcount-1Ϊ0ʱ����������ײ����

int main()
{
    cout << "n = " << n << endl;
    cout << "k = " << k << endl;
    int arr[n];         //ԭ����
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    int result[n];       //result����������������Ҫ�����������ԭ�����е�λ��

    getson(arr, 0, result, k);
    return 0;
}