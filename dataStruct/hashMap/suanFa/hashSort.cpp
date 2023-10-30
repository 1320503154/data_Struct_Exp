#include <iostream>
#include <vector>
#include <stdio.h>
#define MAX_TABLE_LEN 100
using namespace std;

int sort(vector<int> &a)
{
    if (a.empty())
    {
        return 0; // 排序失败
    }
    int hashTable[MAX_TABLE_LEN] = {0};
    for (int i = 0; i < a.size(); i++)
    {
        hashTable[a[i]]++; // 记录a数组中每个元素出现的次数
    }
    int k = 0;
    for (int i = 0; i < MAX_TABLE_LEN; i++) // 从小到大遍历hashTable
    {
        for (int j = 0; j < hashTable[i]; j++) // hashTable[i]表示a数组中的元素出现的次数.a数组中的元素出现几次,则循环几次
        {
            a[k++] = i; // a数组排序
        }
    }
    return 1; // 排序成功
}
int main()
{
    vector<int> a = {7, 17, 5, 8, 2, 9, 20, 3, 2, 5};
    sort(a);
    printf("After sort:\n"); // print function in C
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}