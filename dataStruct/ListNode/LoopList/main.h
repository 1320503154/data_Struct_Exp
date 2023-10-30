#include <stdio.h>
#include <stdlib.h>
typedef struct node
{ // 链表结点类型，包含一个存放整型数据的 data 成员，和一个指向下一个结点的next成员
    int data;
    struct node *next;
} listNode;

// 第一关代码
struct node *createRlist()
{ // 函数功能：创建一个有一个空循环链表，返回值为头指针
    listNode *head = (struct node *)malloc(sizeof(struct node));
    head->data = 0;
    head->next = head;
    return head;
}

struct node *insertOrder(struct node *list, int insData)
{
    // insData = 4;
    // list.data = 1->2->3->4->5->6
    //  在单向递增有序的循环链表（表头指针list）中插入数据元素insData，使之依然有序 。返回值是头指针
    listNode *newNode = (struct node *)malloc(sizeof(listNode));
    newNode->data = insData;
    if (list == NULL)
    {
        newNode->next = newNode; // 把这个节点当做头节点
        return newNode;
    }
    listNode *current = list->next;
    listNode *prevNode = list; // 因为插入节点需要知道该节点的前一个节点

    while (current != list && current->data < insData) // 如果insData大于所有cur.data,则会在最后头节点结束循环
    {
        prevNode = current;      // prev = list->next
        current = current->next; // list->next = list->next->next
    }
    // 此时遍历完成,cur.data>=insData,insData = 4,则此时cur = 5; pre=4
    // 此时pre就是insData的前一个节点
    prevNode->next = newNode;
    newNode->next = current; // 双向链表插入还是很爽的

    if (insData < list->data)
    {
        list = newNode;
    }

    return list;
}
int deleteData(struct node *list, int delData)
{
    // 在单向递增有序循环链表（表头指针list）中删除所有值为delData的结点,返回值为删除结点的个数
    int deleteCount = 0;

    if (list == NULL)
    {
        return deleteCount;
    }

    listNode *current = list->next;
    listNode *prev = list;

    while (current != list) // 当遍历到头结点时停止循环
    {
        if (current->data == delData)
        {
            listNode *temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
            deleteCount++; // 删除结点个数加1
        }
        else // 没找到
        {
            prev = current;          // 前一个节点为当前节点
            current = current->next; // 当前节点为下一个节点
        }
    }

    return deleteCount; // 返回删除结点的个数
}

void printRlist(struct node *list)
{
    // 从链表第一个结点开始输出单向循环链表中各数据元素的值，每输出一个数据元素空一格
    listNode *cur = list->next;
    while (cur->next != list)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("%d ", cur->data);
}
int destroyRlist(struct node *list)
{
    int lastValue = 0;
    if (list == NULL)
    {
        return lastValue;
    }

    listNode *current = list->next; // 从第一个结点开始释放，跳过头结点
    listNode *nextNode = NULL;

    while (current != list) // 当遍历到头结点时停止循环，完成一次循环遍历
    {
        nextNode = current->next;
        lastValue = current->data;
        free(current);
        current = nextNode;
    }

    free(list);
    return lastValue; // 返回最后一个结点的值
}
int main()
{
    struct node *head = createRlist();
    int num, data;
    scanf("%d", &num); // num=6
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &data);
        head = insertOrder(head, data);
    }
    // 存入的数据为 5 2 1 2 2 7
    printRlist(head);
    scanf("%d", &data); // data=2
    printf("\n%d ", deleteData(head, data));

    printf("\n%d ", destroyRlist(head));

    return 1;
}