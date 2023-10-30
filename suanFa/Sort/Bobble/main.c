#include <stdio.h>
#include <stdbool.h>
void swapNum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bobbleSort(int *a, int len)
{
    for (int i = 0; i < len - 1; i++) // 因为每次循环只能排序完成一个数字,从开始要全部遍历一遍,所以外层循环只是为了每次排序 i 个数字
    {
        bool swapped = false;
        for (int j = 0; j < len - 1 - i; j++) // 这里的 -i 只是因为最后已经有i个数字排好序了,就不用交换了,要交换的只是没排好了的
        {
            if (a[j] > a[j + 1]) // 如果左侧数字 大于 右侧数字 5 > 2,{5,2}=>{2,5},把5冒泡到最右边
            {
                swapNum((a + j), (a + j + 1)); // 则交换二者
                swapped = true;                // 发生交换,则TRUE
            }
        }
        if (!swapped)
        {
            break; // 没有发生交换说明已经排序好了,退出循环
        }
    }
}
void printList(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int arr[10] = {3, 5, 7, 2, 9, 0, 6, 1, 8, 4}; // 乱序的
    // 请编写代码对以上数组进行排序
    int length = 10;
    bobbleSort(arr, length);
    printList(arr, length);
}
