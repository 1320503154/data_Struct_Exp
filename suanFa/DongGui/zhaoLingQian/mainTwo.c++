#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 此处bestMatch意思是每个金额的最优解,也就是拼装到指定金额所使用的最少的硬币个数
        vector<int> bestMatch(amount + 1, -1);
        bestMatch[0] = 0;
        // 变量i从 1 循环到给的金额,依次计算靠近给定金额的最优解
        for (int i = 1; i <= amount; i++)
        {
            // 对于每个 i 元,遍历一次整个硬币数组
            for (int j = 0; j < coins.size(); j++)
            {
                // 如果硬币的金额小于i元,并且i元 - 硬币的金额存在最优解
                if (coins[j] <= i && bestMatch[i - coins[j]] != -1)
                {
                    // 如果当前金额没有计算最优解,或者之前的最优解大于现在正在计算的最优解,更新为新循环里面的最优解
                    if (bestMatch[i] == -1 || bestMatch[i] > bestMatch[i - coins[j]] + 1)
                    {
                        bestMatch[i] = bestMatch[i - coins[j]] + 1;
                    }
                }
            }
        }
        return bestMatch[amount];
    }
};
int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    Solution *sol = new Solution;
    int bestNum = sol->coinChange(coins, amount);
    cout << "The res is : " << bestNum << " :endl" << endl;
    delete sol;
    return 0;
}