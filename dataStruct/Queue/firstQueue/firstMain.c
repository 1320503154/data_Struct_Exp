#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
struct seqQueue
{
    int MAXNUM;
    int front, rear;
    DataType *element;
};

typedef struct seqQueue *PseqQueue;

PseqQueue createNullQueue_seq(int m)
{
    if (m == 0)
        return NULL;
    PseqQueue Q = (PseqQueue)malloc(sizeof(struct seqQueue));
    Q->MAXNUM = m + 1;
    Q->front = Q->rear = 0;
    Q->element = (DataType *)malloc(sizeof(DataType) * Q->MAXNUM);
    return Q;
}

int isFullQueue_seq(PseqQueue Q)
{
    return (Q->rear + 1) % Q->MAXNUM == Q->front;
}

int isNullQueue_seq(PseqQueue Q)
{
    return Q->front == Q->rear;
}

int enQueue_seq(PseqQueue Q, DataType x)
{
    if (isFullQueue_seq(Q))
        return 0;

    Q->rear = (Q->rear + 1) % Q->MAXNUM;
    Q->element[Q->rear] = x;
    return 1;
}

DataType delQueue_seq(PseqQueue Q)
{
    if (isNullQueue_seq(Q))
        return -1;

    Q->front = (Q->front + 1) % Q->MAXNUM;
    return Q->element[Q->front];
}

DataType front_seq(PseqQueue Q)
{
    if (isNullQueue_seq(Q))
        return -1;
    return Q->element[(Q->front + 1) % Q->MAXNUM];
}

int main()
{
    PseqQueue Q = createNullQueue_seq(5);
    printf("Is the queue empty? %s\n", isNullQueue_seq(Q) ? "Yes" : "No");

    enQueue_seq(Q, 10);
    enQueue_seq(Q, 20);
    enQueue_seq(Q, 30);

    printf("Front element: %d\n", front_seq(Q));

    printf("Dequeued Element: %d\n", delQueue_seq(Q));
    printf("Dequeued Element: %d\n", delQueue_seq(Q));

    printf("Front element: %d\n", front_seq(Q));

    enQueue_seq(Q, 40);
    enQueue_seq(Q, 50);

    printf("Is the queue full? %s\n", isFullQueue_seq(Q) ? "Yes" : "No");

    printf("Dequeued Element: %d\n", delQueue_seq(Q));
    printf("Dequeued Element: %d\n", delQueue_seq(Q));
    printf("Dequeued Element: %d\n", delQueue_seq(Q));

    printf("Is the queue empty? %s\n", isNullQueue_seq(Q) ? "Yes" : "No");

    free(Q->element);
    free(Q);

    return 0;
}