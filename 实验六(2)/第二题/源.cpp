//Ѱ��ͼ�Ĺؼ�·�� 
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
struct node
{
	int vertex, weight, next;
};


class Graph
{
public:
	int nodeNumber, Link[MAX], count;
	node edge[MAX];

	void insertNode(int n = 0){
		count = n;
		nodeNumber = 0;
		memset(Link, -1, sizeof(Link));
	}
	void addEdge(int vertex_x, int vertex_y, int weight){
 		edge[nodeNumber].vertex = vertex_y;
		edge[nodeNumber].weight = weight;
		edge[nodeNumber].next = Link[vertex_x];
		Link[vertex_x] = nodeNumber;
		nodeNumber++;
	}
	void eraseLink(int vertex){
		Link[vertex] = -1;
	}
};


// ��ͼ�������� 
int topoOrder[MAX];
int inDegree[MAX];	//�������
bool topo(Graph& G, int* topoOrder)
{
	memset(inDegree, 0, sizeof(inDegree));
	for (int i = 0; i < G.count; i++)	//����������
	{
		for (int p = G.Link[i]; p != -1; p = G.edge[p].next)
			inDegree[G.edge[p].vertex]++;
	}

	queue<int> que;		//�����ջ
	for (int i = 0; i < G.count; i++)
		if (inDegree[i] == 0)
			que.push(i);

	int cnt = 0;
	while (!que.empty())	//���ȫ���������
	{
		int vertex = que.front();	//���
		topoOrder[cnt++] = vertex;
		que.pop();

		for (int p = G.Link[vertex]; p != -1; p = G.edge[p].next)
		{
			if (--inDegree[G.edge[p].vertex] == 0)	//��ȼ�һ
				que.push(G.edge[p].vertex);
		}
	}

	return cnt == G.count;
}
//��ͼ�Ĺؼ�·�� 


//���ͼ�Ĺؼ�·��
int criPath[MAX];
void findPrecusorNode(Graph& G, int vertex, int count){
	criPath[count] = vertex;
	//��ǰ�ڵ�û��ǰ���ڵ㣬�Ѿ��ҵ���һ���ؼ�·�� 
	if (G.Link[vertex] == -1)
	{
		for (int i = count; i > 0; i--)
			cout << criPath[i] + 1 << " ";
		cout << criPath[0] + 1 << endl;
	}
	else
	{
		for (int p = G.Link[vertex]; p != -1; p = G.edge[p].next)
			findPrecusorNode(G, G.edge[p].vertex, count + 1);
	}
}

int bigestTime[MAX];
Graph g;
void getCriticalPath(Graph& G, int* topoOrder)
{
	memset(bigestTime, 0, sizeof(bigestTime));
	g.insertNode(G.count);
	for (int i = 0; i < G.count; i++)
	{
		for (int p = G.Link[i]; p != -1; p = G.edge[p].next)
		{
			if (bigestTime[G.edge[p].vertex] < bigestTime[i] + G.edge[p].weight)
			{
				bigestTime[G.edge[p].vertex] = bigestTime[i] + G.edge[p].weight;
				//����ǰ���ڵ�
				g.eraseLink(G.edge[p].vertex);
				g.addEdge(G.edge[p].vertex, i, G.edge[p].weight);
			}
			else
				if (bigestTime[G.edge[p].vertex] == bigestTime[i] + G.edge[p].weight)
					g.addEdge(G.edge[p].vertex, i, G.edge[p].weight);
		}
	}

	int Max_cost = 0;
	for (int i = 0; i < G.count; i++)
		Max_cost = max(Max_cost, bigestTime[i]);

	cout << "�ؼ�·������Ϊ��" << Max_cost << endl;
	for (int i = 0; i < G.count; i++)
		if (bigestTime[i] == Max_cost)
		{
			// ����ؼ�·��
			findPrecusorNode(g, i, 0);
		}
}

void inputEdge(Graph& G) {
	G.addEdge(0, 1, 3);
	G.addEdge(0, 2, 4);
	G.addEdge(0, 3, 5);
	G.addEdge(1, 4, 6);
	G.addEdge(2, 4, 4);
	G.addEdge(2, 5, 4);
	G.addEdge(3, 5, 3);
	G.addEdge(3, 8, 6);
	G.addEdge(4, 6, 5);
	G.addEdge(4, 7, 4);
	G.addEdge(5, 7, 3);
	G.addEdge(5, 8, 4);
	G.addEdge(6, 9, 5);
	G.addEdge(7, 9, 6);
	G.addEdge(8, 9, 4);
}

int main()
{
	Graph G;
	//����10���ڵ�
	G.insertNode(10);
	inputEdge(G);

	if (topo(G, topoOrder))
		getCriticalPath(G, topoOrder);
	else
		cout << "ͼ�д��ڻ����ʲ����ڹؼ�·��";
	return 0;
}