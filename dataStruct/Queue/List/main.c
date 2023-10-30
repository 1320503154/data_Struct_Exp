#include <iostream>
using namespace std;

/*此处是链栈数据结构定义*/
typedef int DataType;
struct node
{
    DataType data;
    struct node *link;
};

typedef struct node *PNode;

struct LinkQueue
{
    PNode front, rear;
};
typedef struct LinkQueue *PLinkQueue;

// 第一关
PLinkQueue createNullQueue_link()
{ // 此处填写代码，创建一个空的链队
    PLinkQueue linkQueue = (PLinkQueue)malloc(sizeof(struct LinkQueue));
    linkQueue->front = linkQueue->rear = NULL;
    return linkQueue;
}

// 第二关
int isNullQueue_link(PLinkQueue L)
{
    // 判断队列是否为空，若为空，返回值为1，否则返回值为0,若队列不存在，则返回-1
    if (L == NULL)
        return -1;
    return L->front == NULL;
}

// 第三关
int EnQueue_link(PLinkQueue L, DataType x)
{ // 在队列插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    PNode node = (PNode)malloc(sizeof(struct node));
    node->data = x;
    node->link = NULL;
    if (L->front == NULL) // 如果原队列为空
    {
        L->front = L->rear = node; // 队首队尾都指向新节点
    }
    else
    {
        L->rear->link = node;    // 在队尾入队
        L->rear = L->rear->link; // 队尾指针指向新节点
    }
}

// 第四关
DataType DeQueue_link(PLinkQueue L)
{ // 删除队首元素并返回被删除元素，若队列为空，则返回-1
    if (isNullQueue_link(L))
        return -1;
    PNode node = L->front;
    DataType value = node->data;
    L->front = L->front->link;
    free(node);
    if (L->front == NULL) // 队列出队完为空队列
        L->rear = NULL;
    return value
}

// 第五关
DataType front_link(PLinkQueue L)
{ // 取队首元素返回，若队列为空，则返回-1
}

// 销毁链队，并释放队列所占存储空间
int destroyQueue_link(PLinkQueue L)
{
    // 返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    int cnt = 0;
    if (L == NULL)
        return 0;
    struct node *p = L->front, *q;
    free(L);
    while (p->link != NULL)
    {
        q = p->link;
        cnt++;
        free(p);
        p = q;
    }
    return cnt;
}
