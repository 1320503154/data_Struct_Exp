#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for singly-linked list.
 */
typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        // 快指针本身不为NULL,快指针的next也不能为NULL,因为是两步,两步跳的.
        // 所以要保证 fast -> next 本身有定义
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next; // 每次走两步
            slow = slow->next;       // 每次走一步
            if (fast == slow)
            {
                // 此时快慢指针相遇,说明链表存在环
                ListNode *index1 = fast; // slow也一样的,此时已经相遇了
                ListNode *index2 = head; // 从头指针开始走
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};
