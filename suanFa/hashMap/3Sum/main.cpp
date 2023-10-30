#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。
// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 最终返回的是数组的值.而不是数组的下标.
// 注意，输出的顺序和三元组的顺序并不重要。
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 双指针法.
        // 定义left和right指针
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 将数组从大到小排序
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0) // 如果最开始的元素都>0,后面的怎么加也不可能了.
            {
                return result;
            }
            // 如何去重? a=nums[i],b=nums[left],c=nums[right];
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue; // continue直接跳过下列循环代码,执行下一个循环体,因为之前的nums[i]已经找到了三元组,后面nums[i+1]肯定组合的也是相同三元祖,直接去重
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    // 说明right指针指向的值太大了,左移
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    // 说明left指针指向的值太小了,left右移.
                    left++;
                }
                else // nums[i] + nums[left] + nums[right] == 0
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 找到之后,再对三元组中的b和c去重
                    // 排序后的数组[ -4, -1, -1, -1, -1, 0, 1, 2]
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    right--;
                    left--; // 找到答案了,双指针同时收缩,找下一轮的答案
                }
            }
        }
    }
};