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

// 直接使用原来的链表来进行移除节点操作：
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // auto middle = head;
        // while (head != NULL)
        // {
        //     if (head->val == val)
        //     {
        //
        //
        //             auto temp = head;
        //             head = head->next;
        //             delete temp;
        //
        //     }
        //     head = head->next; // 继续走结点
        // }
        // return middle;

        // 代码随想录题解:
        // 删除头节点
        while (head != NULL && head->val == val) // 此处没有使用if
        {
            auto temp = head;  // 此处的类型是ListNode *
            head = head->next; // 还是定义一个中间变量然后删除地址.
            delete temp;
        }

        // 删除非头节点
        auto middle = head;
        while (middle != NULL && middle->next != NULL)
        {
            if (middle->next->val == val) // 如果头节点的下一个结点中存储的值==传入的值
            {
                auto temp = middle->next;          // 保存这个符合条件节点的内存地址
                middle->next = middle->next->next; // 让这个内存地址等于下一个节点的内存地址
                delete temp;
            }
            else // 没找到
            {
                middle = middle->next;
            }
        }
        return head;
    }
};