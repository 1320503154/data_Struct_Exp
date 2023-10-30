#include <stdio.h>
#include <stdlib.h>

// 第一关代码
typedef struct node
{
    int data;
    struct node *next;
} List;

struct node *mycreateList()
{
    // 创建只有一个头结点的空链表，头节点的数据域赋值为0，并将表头结点的地址返回
    List *head = (List *)malloc(sizeof(List));
    head->data = 0;
    head->next = NULL;
    return head;
}

// 第二关代码
void myinsertHead(struct node *head, int insData)
{
    // 在head为表头的链表头插入数据元素insData
    List *newNode = (List *)malloc(sizeof(List));
    newNode->data = insData;
    newNode->next = head->next;
    head->next = newNode;
}

void myinsertTail(struct node *head, int insData)
{
    // 在head为表头的链表表尾插入数据元素insData
    List *newNode = (List *)malloc(sizeof(List));
    newNode->data = insData;
    newNode->next = NULL;
    if (head->next == NULL) // 如果只有头节点
    {
        head->next = newNode; // 直接续到后面
    }
    else // 这里没有else导致死循环,如果还有后面的节点
    {
        List *cur = head->next;   // 保存head.next
        while (cur->next != NULL) // 直接跑到最后面
        {
            cur = cur->next;
        }
        cur->next = newNode; // 续上节点
    }
}

void myprintList(struct node *L)
{
    // 输出数据并换行
    List *cur = L->next;
    while (cur != NULL)
    {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
}
// 第三关代码
void reverseList_link(struct node *L)
{
    // 请在此处填入代码，实现链表逆置功能
    List *temp = NULL;
    List *cur = L->next;
    List *pre = NULL;
    // dummyHead->1->2->3->4->NULL;
    // L=dummyHead;
    // cur=1->2;
    // 开始循环:
    // temp=2->3 cur=1->NULL pre=cur=1->NULL cur=temp=2->3
    // temp=3->4 cur=2->(pre=1->NULL) pre=cur=2->(pre=1->NULL) cur = 3->4
    // temp=4->NULL cur=3->(pre=2->1->NULL) pre=cur=3->2->1->NULL cur=4->NUll;
    // temp = NULL cur=temp=NULL;
    // 结束循环
    while (cur) // 当cur==NULL时,循环结束
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    L = pre;
}
// 第四关代码
int locateAndChange(struct node *L, int data)
{
    // 请在此处填入代码，在头结点为L的链表中查找 与data值相等的第一个结点，若能找到该结点，则将该结点的值与前驱结点的值交换
    // 若未找到与data值相等的结点，则返回值为-1，若找到的结点无前驱结点，则返回值为0，否则返回值为前驱结点的值
    // begin
    if (L == NULL || L->next == NULL)
    {
        return -1;
    }

    List *prev = L;      // 前驱结点
    List *cur = L->next; // 当前结点

    while (cur != NULL)
    {
        if (cur->data == target) // 找到与 target 值相等的结点
        {
            int temp = cur->data;
            cur->data = prev->data;
            prev->data = temp;

            if (prev == L)
            {
                return 0;
            }
            else
            {
                return cur->data;
            }
        }

        prev = cur;
        cur = cur->next;
    }

    return -1; // 未找到与 target 值相等的结点
    // end
}

// 第五关代码
int destroyList(struct node *L)
{
    // 请在此处填写代码，实现将链表L的结点空间回收
    // 返回值为回收结点的个数，含头结点在内
    int size = 0;
    while (L != NULL)
    {
        List *temp = L;
        free(temp);
        size++;
        L = L->next;
    }
    return size;
}
