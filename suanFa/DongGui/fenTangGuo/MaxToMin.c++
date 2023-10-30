#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &hunger, vector<int> &candy)
    {
        // 判断数组是否为空
        if (hunger.empty() || candy.empty())
        {
            return 0;
        }
        // 排序
        sort(hunger.begin(), hunger.end());
        sort(candy.begin(), candy.end());
        // 开始循环,从大到小分糖果
        int childMax = hunger.size() - 1;
        int candyMax = candy.size() - 1;
        int hasFinishNum = 0;
        while (childMax >= 0 && candyMax >= 0)
        {
            if (candy[candyMax] >= hunger[childMax])
            {
                hasFinishNum++;
                childMax--;
                candyMax--;
            }
            else
            {
                childMax--; // 这里应该是儿童的指针下移,因为糖果不满足需求,找到满足需求的人
            }
        }
        return hasFinishNum; // 最终返回的是已经被分好糖果的人
    }
};

int main()
{
    vector<int> hunger = {1, 2, 3}; // size = 2
    vector<int> candy = {1, 1};     // size = 3
    Solution *solution = new Solution;
    int childNum = solution->findContentChildren(hunger, candy);
    cout << "childNum: " << childNum << endl;
    delete solution;
    return 0;
}