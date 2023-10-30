#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {} // 节点的构造函数
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
void deleteList(ListNode *head)
{
    while (head != NULL)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}
// 写一个删除节点的函数
void deleteNode(ListNode *node)
{
    // 1.将node节点的值更新为下一个节点的值
    node->val = node->next->val;
    // 2.将node节点的next指针指向下一个节点的next指针
    node->next = node->next->next;
    // 3.删除下一个节点
    delete node->next;
}
// 写一个增加节点的函数
void addNode(ListNode *node, int val)
{
    ListNode *temp = new ListNode(val);
    temp->next = node->next;
    node->next = temp;
}
int main()
{
    ListNode *pre = new ListNode(0);
    // 初始化一些数据
    auto head = pre; // 事先保存头节点
    for (int i = 1; i < 10; i++)
    {
        ListNode *temp = new ListNode(i); // 创建新节点
        pre->next = temp;                 // 将新节点连接到链表上
        pre = temp;                       // 更新pre指针
    }
    // 为什么要更新pre指针?
    //  因为pre指针指向的是链表的最后一个节点,如果不更新pre指针,那么pre指针将永远指向最后一个节点
    printf("before delete:\n");
    printList(head);
    // 删除第一个节点
    head = head->next;
    printf("after delete:\n");
    printList(head);
}
