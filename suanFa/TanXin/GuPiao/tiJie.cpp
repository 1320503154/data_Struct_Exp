#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         // 题解版本,大概是动态规划
//         int cost = 0;
//         int profit = 0;
//         for (int price : prices)
//         {
//             cout << price << " ";
//         }
//         cout << endl;
//         return 0;
//     }
// };
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 题解版本,大概是动态规划

        int cost = 0; // 买入价格,初始化应该为int 的最大值
        // 因为逻辑是选择最小的price,如果初始化为0,则,第一次就是cost,cost将不会改变.
        int profit = 0;
        for (int price : prices)
        {
            cost = min(cost, price);
            profit = max(price - cost, profit);
        }
        return profit;
    }
};
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // 编写测试用例
    Solution *solution = new Solution();
    int result = solution->maxProfit(prices);
    cout << "result: " << result << endl;
    delete solution;
    return 0;
}