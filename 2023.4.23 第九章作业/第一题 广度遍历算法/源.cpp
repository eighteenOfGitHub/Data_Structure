int visited[20] = { 0 };  //ȫ��������,���Ա��ĳ�������Ƿ񱻷��ʹ�

void DFSl(ALGraph G, int i)
{  //�Ӷ���Vi����,���������������ͼG(�ڽӱ�ṹ)
    EdgeNode* p;
    int j;
    visited[i] = 1;     //���vi�ѷ��ʹ�
    p = G[i].link;      //ȡVi�ڽӱ�ı�ͷָ��
    while (p != NULL)   //��������vi��ÿ���ڽӵ�
    {
        j = p->adjvex;  // jΪvi��һ���ڽӵ����
        if (!visited[j])
            DFSl(G, j);  //��(vi,vj)��E(G),��vjδ�����ʹ�,��ӿ�ʼ�ݹ����
        p = p->next;     //ʹpָ��vi����һ���ڽӵ�
    }                    // End-while
}
