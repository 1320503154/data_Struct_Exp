#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> oldPrices(prices);
        sort(prices.begin(), prices.end());
        int minMoney = prices[0];
        int maxMoney = prices.back();
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (minMoney == oldPrices[i])
            {
                minIndex = i;
                break;
            }
        }
        for (int i = 0; i < prices.size(); i++)
        {
            if (maxMoney == oldPrices[i])
            {
                maxIndex = i;
                break;
            }
        }
        if (minIndex < maxIndex)
        {
            return maxMoney - minMoney;
        }
        else
        {
            return 0;
        }
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