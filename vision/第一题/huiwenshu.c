#include <stdio.h>
#include <stdlib.h>
int isHuiWen(int num)
{
    int oldNum = num;
    int newNum = 0;
    while (num > 0)
    {
        newNum = newNum * 10 + num % 10;
        num /= 10;
    }
    return newNum == oldNum ? 1 : 0;
}
int main()
{
    // 输入为1行，分别表示两个正整数a和b
    // 输出为一行，表示a到b之间（包括a和b）所有的回文数个数之和
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        if (isHuiWen(i))
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}