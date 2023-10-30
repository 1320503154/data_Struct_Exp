#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // 暴力遍历方法.
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == val)
            {
                for (int j = i + 1; j < len; j++)
                {
                    nums[j - 1] = nums[j]; // j=i+1, j-1 = i+1-1 = i;
                }
                i--;   // 因为下标i以后的数值都向前移动了一位,所以i也向前移动一位
                len--; // 大小--
            }
        }
        return len;
    }
};
// 双指针法.通过一个快指针和一个慢指针,在一个for循环下完成两个for循环的工作.
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex]) // 找到不等于val=3的元素
            {
                nums[slowIndex] = nums[fastIndex]; // 把数组最前面的下标对应的内存空间留给 != val 的元素.
                slowIndex++;
            }
        }
        return slowIndex;
    }
};
// 有序数组的平方
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int k = nums.size() - 1; // 指向数组的末尾元素
        // 双指针,创建新数组,将元素从大到小放到新数组内部
        vector<int> result(nums.size(), 0);
        for (int i = 0, j = nums.size() - 1; i <= j;) // 一个指向头,一个指向尾
        {
            if (nums[i] * nums[i] > nums[j] * nums[j])
            {
                result[k] = nums[i] * nums[i];
                k--;
                i++;
            }
            else
            { // nums[i] * nums[i]<=nums[j] * nums[j]
                result[k] = nums[j] * nums[j];
                j--;
                k--;
            }
        }
        return nums;
    }
};
// 209,长度最小的子数组.滑动窗口法.
class Solution
{
public:
    // target = 7, nums = [2,3,1,2,4,3]
    // 输出：2
    // 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组,并返回其长度.
    //  解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int result = INT_MAX;
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++)
        {
            //
            sum += nums[fast]; // sum 收集nums里面的元素.就是滑动窗口里面的元素.
            while (sum >= target)
            {
                subLength = j - i;               // 最小的长度
                result = min(result, subLength); // 最终返回result.
                sum -= nums[slow];
                slow++;
            }
        }
        return result;
    }
};