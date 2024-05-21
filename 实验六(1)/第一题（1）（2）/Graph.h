#pragma once
#include<iostream>
using namespace std;
const int MAX = 100;


class Graph {
private:
	int vertex[MAX];	//顶点表
	int edge[MAX][MAX];	//边
	int count;			//当前定点数

public:
	Graph() { count = 0; }
	~Graph() {}
	
	bool insert(int data);						//插入点
	bool connect(int point1, int point2);		//连接

	int getEdgeCount();							//获得边的数量
	bool isTree();								//判断是否为树接口
	int getCount() { return count; }			//获得点的数量

private:
	void isTree(int point1, int prepoint, bool visited[MAX], bool& flag);	//判断是否为树接口
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
	if (point1 >= count || point2 >= count) {		//越界不连
		return false;
	}
	if (point1 == point2) {	//相同不连
		return false;
	}
	if (edge[point1][point2] == true && edge[point2][point1] == true) {	//已连不连
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
	for (int i = 0; i < count; i++) {		//初始化
		visited[i] = false;
	}
	bool flag = true;
	isTree(0, 0,visited, flag);
	return flag;
}

void Graph::isTree(int point, int prepoint, bool visited[MAX], bool& flag)		//深度优先
{
	if (flag == false) {				//已经确定不为树，则直接返回
		return;
	}
	if (visited[point] == true) {		//如果该点已被探索过，则不为树
		flag = false;
	}
	visited[point] = true;
	for (int i = 0; i < count; i++) {	//广度遍历邻接点
		if (prepoint!= i && edge[point][i] == 1) {
			isTree(i, point, visited, flag);
		}
	}
}