#include <stdio.h>
#include <stdlib.h>

/*此处是顺序线性表数据结构定义*/
typedef int DataType;
struct seqList
{                      // 有3个数据成员
    int MAXNUM;        // 用于记录顺序线性表中能存放的最大元素个数的 整型 MAXNUM
    int curNum;        // 用于存放顺序线性表中数据元素的个数  整型  curNum
    DataType *element; // 用于存放顺序线性表数据元素的连续空间的起始地址
};

typedef struct seqList *PseqList;

/*创建空的顺序线性表，能存放的最大元素个数为 m*/
PseqList createNullList_seq(int m)
{ // 若m=0，则返回NULL
    PseqList plist = (struct seqList *)malloc(sizeof(struct seqList));
    if (plist == NULL)
        return NULL; // 分配空间失败
    plist->MAXNUM = m;
    plist->curNum = 0;
    plist->element = (DataType *)malloc(sizeof(DataType) * m);
    if (plist->element == NULL)
    {
        free(plist);
        return NULL;
    }
    return plist;
}

/*在线性表表尾插入数据元素,返回值0表示插入失败，返回值1表示在表尾插入成功*/
int insertP_tail(PseqList plist, int x)
{
    if (plist->curNum == plist->MAXNUM) // 若表满，则无法插入
    {
        printf("list if full !");
        return 0;
    }
    plist->element[plist->curNum] = x;
    plist->curNum++;
    return 1;
}

/*回收线性表占用的空间*/
int destroyList_seq(PseqList plist)
{
    // 返回值为销毁的线性表中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (plist == NULL)
        return 0;
    int m = plist->curNum;
    free(plist->element);
    free(plist);
    return m;
}

void printList_seq(PseqList plist)
{ // 逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    for (int i = 0; i < plist->curNum; i++)
        printf("%d ", plist->element[i]);
}

// 第一关:求顺序线性表中连续子表（最少有一个元素）的最大和并输出
int seqMaxSum(PseqList plist)
{
    // 初始化最大值和走动的指针都为数组第一个值
    int maxSum = plist->element[0];
    int currentSum = plist->element[0];
    for (int i = 1; i < plist->curNum; i++)
    {
        if (currentSum + plist->element[i] > plist->element[i])
        {
            // 上面就是我现在的值,加上数组的值,大于数组原本元素的值,则更新curSum
            currentSum += plist->element[i];
        }
        else
        { // <=,说明数组元素nb

            currentSum = plist->element[i];
        }
        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

void swapNum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bobbleSort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swapNum((a + j), (a + j + 1));
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
// 第二关：寻找线性表中没有出现的最小的正整数
int findMinNumber(PseqList plist)
{
    // 若线性表为空，则返回0
    if (plist->curNum == 0)
    {
        return 0;
    }
    int minNum = plist->element[0];
    int maxNum = plist->element[0];
    for (int i = 0; i < plist->curNum; i++)
    {
        if (plist->element[i] > 0)
        {
            minNum = min(plist->element[i], minNum);
            maxNum = max(plist->element[i], maxNum);
        }
    }
    minNum--;
    maxNum++;
    if (minNum > 0)
    {
        return minNum;
    }
    return maxNum;
}

// 第三关：找出给定目标值target在有序线性表中出现的起始位置和结束位置
void findPos(PseqList plist, int target, int *pos)
{
    // // 起始位置放在pos[0], 结束位置放在pos[1]
    // int start = 0;
    // int end = 0;
    // int flag = 0;
    // for (int i = 0; i < plist->curNum; i++)
    // {
    //     if (target == plist->element[i])
    //     {
    //         end = i;
    //         flag++;
    //     }
    // }
    // start = end - flag;
    // start++;
    // pos[0] = start;
    // pos[1] = end;

    // 尝试使用二分查找算法.因为是有序数组

    pos[0] = -1;
    pos[1] = -1;

    int left = 0;                  // 第一个元素的下标
    int right = plist->curNum - 1; // 最后一个元素的下标

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // c语言里,整数/2,向下取整

        if (plist->element[mid] == target)
        {
            // 找到目标值,向左和右搜索
            pos[0] = mid;
            pos[1] = mid;
            // on left
            for (int i = mid - 1; i >= 0; i--)
            {
                if (plist->element[i] == target)
                {
                    pos[0] = i;
                }
                else
                {
                    break;
                }
            }
            // on right
            for (int i = mid + 1; i < plist->curNum; i++)
            {
                if (plist->element[i] == target)
                {
                    pos[1] = i;
                }
                else
                {
                    break;
                }
            }
        }
        else if (plist->element[mid] < target)
        {
            left = mid + 1;
        }
        else // plist->element[mid] > target
        {
            right = mid - 1;
        }
    }
}
