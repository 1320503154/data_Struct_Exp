#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        vector<int> numsTwo;
        int j = 0;
        for (int i = 0; i < nums.size() - 1; i++) // 此处应该是总size长度-1,因为size是总数据元素的个数,但是下标从0开始的
        {
            if (nums[i] == nums[i + 1]) // 相同存的话,不是去重.
            {
                numsTwo[j] = nums[i]; // numsTwo 是一个空向量，您试图使用下标 j 来赋值，但这会导致越界访问。需要使用 push_back() 函数向 numsTwo 中添加元素。
                j++;
            }
        }
        nums = numsTwo;
        return numsTwo.size();
    }
};
// 以下是修改后的代码
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int> numsTwo;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] != nums[i + 1])
            {
                numsTwo.push_back(nums[i]);
            }
        }
        numsTwo.push_back(nums[nums.size() - 1]);
        nums = numsTwo;
        return numsTwo.size();
    }
};
// 双指针
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++)
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};