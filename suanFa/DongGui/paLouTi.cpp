// n=0,1
// n=1,1
// n=2,1+1,2, two methods
// n=3,if 1 ,2; if 2,1,three methods .
// 不断的有分支

// class Solution {
// public:
//     int climbStairs(int n) {
//         //递归无法解题,时间太长了
//         //递归没有缓存,或者人为设计缓存
//         //动态规划:有缓存的迭代.
//         if(n==1) return 1;
//         if(n==2) return 2;
//         return climbStairs(n-1) + climbStairs(n-2);//这就是状态转移方程
//     }
// };
// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         // 动态规划:有缓存数组的的迭代.
//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;
//         vector<long long> dp(n + 1, 0);
//         dp[0] = 1; // 别忘记给动态规划数组初始化
//         dp[1] = 2;
//         for (int i = 2; i <= n; i++)
//         {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }
//         return dp[n - 1]; // 数组从0开始
//     }
// };

// 合并两个有序链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(0);
        auto middle = head; // 保存此时头节点的内存地址
        while (l1 && l2)
        {
            // 因为要求返回的节点列表是从小到大排序.找小的即可
            if (l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
            }
            else // l1.val >= l2.val
            {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next; // 目的就是为了更新链接节点.
            // 无论是将l1还是l2的节点链接到head之后，之后都更新head指针，使其指向当前链接的节点(l1或者是l2)。这样，在循环迭代的过程中，head指针一直向链表的末尾移动，最终指向最后一个节点。
        }
        // 如果l1遍历完了,但是l2还没完呢??直接把排序好的l1 || l2链接在head后面即可;
        head->next = l1 ? l1 : l2;

        return middle->next;
    }
};