#include <stdio.h>
void func(int n)
{
    int i = 0, s = 0;
    while (s <= n)
    {
        i++;
        s = s + i;
        printf("S 是 %d,i 是 %d.\n", s, i);
    }
}
int main()
{
    int n = 5;
    func(6);
}
