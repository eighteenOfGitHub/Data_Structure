#pragma once
#include<iostream>
using namespace std;
const int MAX = 100;


class Graph {
private:
	int vertex[MAX];	//�����
	int edge[MAX][MAX];	//��
	int count;			//��ǰ������

public:
	Graph() { count = 0; }
	~Graph() {}
	
	bool insert(int data);						//�����
	bool connect(int point1, int point2);		//����

	int getEdgeCount();							//��ñߵ�����
	bool isTree();								//�ж��Ƿ�Ϊ���ӿ�
	int getCount() { return count; }			//��õ������

private:
	void isTree(int point1, int prepoint, bool visited[MAX], bool& flag);	//�ж��Ƿ�Ϊ���ӿ�
};

inline bool Graph::insert(int data){
	if (count == MAX) {
		return false;
	}
	vertex[count] = data;
	count++;
	return true;
}

inline bool Graph::connect(int point1, int point2){
	if (point1 >= count || point2 >= count) {		//Խ�粻��
		return false;
	}
	if (point1 == point2) {	//��ͬ����
		return false;
	}
	if (edge[point1][point2] == true && edge[point2][point1] == true) {	//��������
		return false;
	}
	edge[point1][point2] = true;
	edge[point2][point1] = true;

	return true;
}

int Graph::getEdgeCount() {
	int edgeCount = 0;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (edge[i][j] == 1) {
				edgeCount++;
			}
		}
	}
	return edgeCount / 2;
}

bool Graph::isTree(){
	bool visited[MAX];
	for (int i = 0; i < count; i++) {		//��ʼ��
		visited[i] = false;
	}
	bool flag = true;
	isTree(0, 0,visited, flag);
	return flag;
}

void Graph::isTree(int point, int prepoint, bool visited[MAX], bool& flag)		//�������
{
	if (flag == false) {				//�Ѿ�ȷ����Ϊ������ֱ�ӷ���
		return;
	}
	if (visited[point] == true) {		//����õ��ѱ�̽��������Ϊ��
		flag = false;
	}
	visited[point] = true;
	for (int i = 0; i < count; i++) {	//��ȱ����ڽӵ�
		if (prepoint!= i && edge[point][i] == 1) {
			isTree(i, point, visited, flag);
		}
	}
}