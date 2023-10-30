// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

// 输入：n = 4, k = 2
// 输出：
// [
//     [ 2, 4 ], index=0;
//     [ 3, 4 ], index=1;
//     [ 2, 3 ], index=2;
//     [ 1, 2 ], index=3;
//     [ 1, 3 ], index=4;
//     [ 1, 4 ], index=5;
// ]
// 返回的二维数组,其实就是数组里面存储数组.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    // 第一步递归函数的返回值和参数
    // n=4 , 1 2 3 4 ; k=2
    void backTracking(int n, int k, int startIndex)
    {
        // 第二步终止递归的条件
        if (path.size() == k) // path中的数目已经是k=2个了
        {
            result.push_back(path); // 存储结果
            return;
        }
        // 单层搜索的逻辑
        for (int i = startIndex; i <= n; i++)
        {
            // 第一次循环:i=1
            path.push_back(i);         // path=[1]
            backTracking(n, k, i + 1); // path=[1,2],此时path的size=k了,然后存储结果,return,执行下面的语句.
            path.pop_back();           // path = [1]
            // 第二次循环:i=2
            // path=[1,2]
            // back 停止,and path=[1],回溯!!!!!!!!!
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backTracking(n, k, 1);
        return result;
    }
};
int main()
{
    vector<vector<int>> solutions;
    Solution *sol = new Solution();
    solutions = sol->combine(1, 1);
    for (vector<int> &item : solutions)
    {
        cout << item[0] << "," << item[1] << endl;
    }
}