#include <stdio.h>
#include <stdlib.h>
/*此处是顺序队列数据结构定义*/
typedef int DataType;
struct seqQueue
{
    int MAXNUM;        // 用于记录顺序队列中能存放的最大元素个数，整型
    int front, rear;   // 用于存放顺序队列的队首，队尾
    DataType *element; // 用于存放数据元素的连续空间的起始地址
};

typedef struct seqQueue *PseqQueue;
// 第一关
PseqQueue createNullQueue_seq(int m)
{ // 此处填写代码，创建一个空的环形队列，能存放的最大元素个数为 m
    // 若m=0，则返回NULL
    if (m == 0)
        return NULL;
    PseqQueue Q = (PseqQueue)malloc(sizeof(struct seqQueue));
    Q->MAXNUM = m + 1;
    Q->front = Q->rear = 0;
    Q->element = (DataType *)malloc(sizeof(DataType) * Q->MAXNUM);
    return Q;
}

// 第二关
int isNullQueue_seq(PseqQueue Q)
{
    // 判断顺序（环形）队列是否为空，若为空，返回值为1，否则返回值为0,若队列不存在，则返回-1
    if (Q == NULL)
        return -1;
    if (Q->front == Q->rear)
        return 1;
    else
        return 0;
}

// 第三关
int isFullQueue_seq(PseqQueue Q)
{
    // 判断环形队列是否已满，若已满，返回值为1，否则返回值为0
    if (Q->front == (Q->rear + 1) % Q->MAXNUM)
        return 1;
    else
        return 0;
}

// 第四关
int enQueue_seq(PseqQueue Q, DataType x)
{ // 在环形队列中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if (isFullQueue_seq(Q))
        return 0;

    Q->rear = (Q->rear + 1) % Q->MAXNUM; // 队尾指针后移
    Q->element[Q->rear] = x;             // 插入元素
    return 1;
}

// 第五关
DataType delQueue_seq(PseqQueue Q)
{ // 出队并返回删除元素，若队列为空，则返回-1
    if (isNullQueue_seq(Q))
        return -1;

    Q->front = (Q->front + 1) % Q->MAXNUM; // 队首指针后移
    return Q->element[Q->front];           // 返回删除的元素
}

// 第六关
DataType front_seq(PseqQueue Q)
{                           // 取队首元素返回，若队列为空，则返回-1
    if (isNullQueue_seq(Q)) // 队列为空
        return -1;
    return Q->element[(Q->front + 1) % Q->MAXNUM]; // 返回队首元素
}
// 销毁环形队列，释放队列所占存储空间
int destroyQueue_seq(PseqQueue Q)
{
    // 返回值为销毁的队列中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (Q == NULL)
        return 0;

    int count = 0;
    while (!isNullQueue_seq(Q)) // 队列不为空
    {
        delQueue_seq(Q); // 删除队列元素
        count++;
    }

    free(Q->element); // 释放存储空间
    free(Q);          // 释放结构体内存
    return count;
}
// 第七关
void queueApp(int a[], int n)
{
    // 参数用于传递顾客编号和顾客人数，输出顾客接受服务后离开顺序
    // 问题描述：设某银行有A、B两个业务窗口，A窗口处理业务的速度是B窗口的2倍，即A处理完2个业务，B才处理完一个。
    // 给定银行的顾客序列，请按业务完成顺序输出顾客序列。假定不考虑顾客到达的时间间隔，并且当A、B两个窗口同时处理完顾客时，A窗口的顾客先离开。
    // 输入一行整数，第一个数字是顾客的总数N（N < 1000）, 后面跟N个整数代表顾客的编号，假定编号为奇数的顾客去A窗口处理业务，而编号为偶数的顾客去B窗口处理业务。
    PseqQueue A = createNullQueue_seq(n);
    PseqQueue B = createNullQueue_seq(n);

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            enQueue_seq(B, a[i]); // 偶数
        else
            enQueue_seq(A, a[i]); // 奇数
    }
    // 顾客接受服务后离开顺序
    int count = 0;
    while (count < n)
    {
        if (!isNullQueue_seq(A))
        {
            printf("%d ", front_seq(A));
            delQueue_seq(A);
            count++;
        }
        if (!isNullQueue_seq(A))
        {
            printf("%d ", front_seq(A));
            delQueue_seq(A);
            count++;
        }
        // A处理完2个业务，B才处理完一个
        if (!isNullQueue_seq(B))
        {
            printf("%d ", front_seq(B));
            delQueue_seq(B);
            count++;
        }
    }
    // 销毁队列
    destroyQueue_seq(A);
    destroyQueue_seq(B);
}

int main(void)
{
    int m, a[8];
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    queueApp(a, m);
}