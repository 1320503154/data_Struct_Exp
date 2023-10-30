#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void coinChange(vector<int> &coins, int amount)
    {
        vector<int> bestMatch(amount + 1, -1); // 最优解数组
        bestMatch[0] = 0;
        }
};
int main()
{
    // dp[money]表示金额为money时的最优解
    // 定义dp数组,长度为amount + 1,下标0初始化为0,表示金额为0时的最优解为0,其余下标的初始化值为-1
    int amount = 14;
    vector<int> coins = {1, 2, 5, 7, 10};
    vector<int> dp(amount + 1, -1); // 向量的长度为"amount + 1"，并且每个元素的初始值都被设置为-1。
    dp[0] = 0;
}