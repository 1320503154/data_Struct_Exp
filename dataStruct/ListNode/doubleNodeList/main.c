#include <stdio.h>
#include <stdlib.h>
typedef struct node
{ // 链表结点类型，包含一个存放整型数据的 data 成员，和指向前驱和后继结点的指针
    int data;
    struct node *prev, *next;
} listNode;

typedef struct Hnode
{
    // 双向链表头结点,有两个指针成员，分别指向双向链表的第一个结点和最后一个结点
    struct node *head, *tail;
    int size; // 万金油参数,写任何数据结构都需要,用来判断表是否为NULL,求链表数据的个数
} headNode;

// 第二关代码
struct Hnode *createDlist()
{ // 函数功能：创建一个带头结点的双向链表，tail指向尾结点；head指针指向第一个结点，返回值是指向头结点的指针
    headNode *list = (struct Hnode *)malloc(sizeof(struct Hnode));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
listNode *createNode(int nodeData) // 创建一个节点
{
    listNode *node = (struct node *)malloc(sizeof(struct node));
    node->data = nodeData;
    node->prev = node->next = NULL;
    return node;
}
void insertDlist(struct Hnode *list, int insData)
{
    // 在双向链表的表头插入数据
    listNode *newNode = createNode(insData);
    if (list->head == NULL)
    { // 空链表
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {

        newNode->next = list->head; // 新插入的节点链接原来的节点
        // 因为list->head存的是原来表头节点的内存地址
        list->head->prev = newNode;
        list->head = newNode; // 表头节点只是为了记录第一个节点和最后一个节点的内存地址
        // firstNode和lastNode.
    }
}

int deleteData(struct Hnode *list, int delData)
{
    // 在双向链表中删除值为delData的第一个结点，若删除成功返回1，否则返回0
    if (list == NULL || list->head == NULL)
    {
        return 0;
    }
    if (list->head->data == delData)
    {
        listNode *temp = list->head;
        list->head = list->head->next;
        if (list->head != NULL)
        {
            list->head->prev = NULL;
        }
        else
        {
            list->tail = NULL;
        }
        free(temp);
        return 1;
    }
    listNode *pMover = list->head->next;
    while (pMover != NULL)
    {
        if (delData == pMover->data)
        {
            pMover->prev->next = pMover->next;
            if (pMover->next != NULL)
            {
                pMover->next->prev = pMover->prev;
            }
            else
            {
                list->tail = pMover->prev;
            }
            free(pMover);
            return 1;
        }
        pMover = pMover->next;
    }
    return 0;
}

void printDlist(struct Hnode *list)
{
    // 输出双向循环链表中各数据元素的值，每输出一个数据元素换行

    // 定义一个移动的指针做打印
    listNode *pointerMover = list->head;
    while (pointerMover != NULL)
    {
        printf("%d\n", pointerMover->data);
        pointerMover = pointerMover->next;
    }
}

int destroyDlist(struct Hnode *list)
{ // 释放双向链表占用的存储空间，释放所有结点,返回释放的结点数，不含list本身
  // 当作单向链表操作即可
    if (list == NULL)
    {
        return 0;
    }
    int delCount = 0;
    listNode *curMover = list->head;
    while (curMover != NULL)
    {
        listNode *temp = curMover;
        curMover = curMover->next;
        free(temp);
        delCount++;
    }
    list->head = NULL;
    list->tail = NULL;
    return delCount;
}
int main()
{
    struct Hnode *head = createDlist();
    int num, data;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        insertDlist(head, data);
    }
    printDlist(head);
    scanf("%d", &data);
    printf("\n%d ", deleteData(head, data));

    printf("\n%d ", destroyDlist(head));

    return 1;
}