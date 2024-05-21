int visited[20] = { 0 };  //全局量数组,用以标记某个顶点是否被访问过

void DFSl(ALGraph G, int i)
{  //从顶点Vi出发,深度优先搜索遍历图G(邻接表结构)
    EdgeNode* p;
    int j;
    visited[i] = 1;     //标记vi已访问过
    p = G[i].link;      //取Vi邻接表的表头指针
    while (p != NULL)   //依次搜索vi的每个邻接点
    {
        j = p->adjvex;  // j为vi的一个邻接点序号
        if (!visited[j])
            DFSl(G, j);  //若(vi,vj)∈E(G),且vj未被访问过,则从开始递归调用
        p = p->next;     //使p指向vi的下一个邻接点
    }                    // End-while
}
