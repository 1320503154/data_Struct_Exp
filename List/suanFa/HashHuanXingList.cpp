#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
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
        unordered_set<ListNode *> visited;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            if (visited.count(slow)) // 使用 count 函数检查 unordered_set 中是否包含指定的元素。存在返回true
            {
                return slow; // 这里的slow节点已经是当时环的进入节点了.
            }
            visited.insert(slow); // 因为unordered_set是类似于哈希表的集合,每个元素都不一样,然后slow内部存储的内存地址都不一样.
            slow = slow->next;
            fast = fast->next->next;
        }
        return NULL;
    }
};