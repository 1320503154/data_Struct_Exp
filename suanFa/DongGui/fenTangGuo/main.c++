#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &hunger, vector<int> &candy)
    {
        if (hunger.empty() || candy.empty())
        {
            return 0;
        }
        sort(hunger.begin(), hunger.end());
        sort(candy.begin(), candy.end());
        int childNum = 0;
        int candyNum = 0;
        while (childNum < hunger.size() && candyNum < candy.size())
        {
            if (candy[candyNum] >= hunger[childNum])
            {
                childNum++;
                candyNum++;
            }
            else
            {
                candyNum++;
            }
        }
        return childNum;
    }
};
// 看上面代码出错的原因
//  1. 未考虑到数组为空
//  编写一些测试用例
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