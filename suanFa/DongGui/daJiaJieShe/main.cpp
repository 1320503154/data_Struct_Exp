#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_TABLE_LEN 100
using namespace std;
// class Solution
// {
// public:
//     void rob(vector<int> &nums)
//     {
//         vector<int> dp(nums.size(), 0);
//         // dp数组的含义是
//         dp[0] = nums[0];               // 偷第一家
//         dp[1] = max(nums[0], nums[1]); // 比较第一家和第二家.
//         for (int i = 2; i < nums.size(); i++)
//         {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//             // 偷第i家,则i-1不能偷,看下dp[i-2]
//         }
//         for (const &it : dp)
//         {
//             printf("数组的元素是: %d\n", it);
//         }
//     }
// };
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        // dp数组的含义是
        dp[0] = nums[0];               // 偷第一家
        dp[1] = max(nums[0], nums[1]); // 比较第一家和第二家.
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            // 偷第i家,则i-1不能偷,看下dp[i-2]
        }
        return dp.back();
    }
};
// 编写测试用例
int main()
{
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution *solution = new Solution();
    solution->rob(nums);
    delete solution;
    return 0;
}
