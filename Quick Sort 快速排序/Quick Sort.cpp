#include<iostream>
using namespace std;

void Print(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

//对数组A中下标为s～t的子表进行划分
void partition(int A[], int s, int t, int* cutpoint){
	int x = A[s];     //保存中间元素，腾出空位
	int i = s, j = t; //更新上下标
	while (i != j) {
		while (i<j && A[j] > x)   
			j--;
		if (i < j) { 
			A[i] = A[j];  i = i + 1; 
		}
		while (i < j && A[i] < x)   
			i++;
		if (i < j) { 
			A[j] = A[i];   j = j - 1; 
		}
	}
	A[i] = x;  
	*cutpoint = i;
}

//对数组A中下标从s到t的元素组成的子表快速排序
void Quick_sort(int A[], int s, int t) {
	if (s < t) {
		int* i = new int(0);
		partition(A, s, t, i);		//划分
		
		cout << "快速排序 从 " << s << " 到 " << t << " :" << endl;
		Print(A, 16);

		Quick_sort(A, s, *i - 1);	//对前面子表快速排序
		Quick_sort(A, *i + 1, t);	//对后面子表快速排序
	}
}

void test(){
	int A[16] = { 50, 30, 120, 25, 85, 40, 100, 12, 90, 15, 60, 35, 105, 78, 10, 28};
	Quick_sort(A, 0, 15);
}

int main(){
	test();
	return 0;
}
