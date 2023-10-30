#include <stdio.h>
#include <math.h>

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    int base = minutesToTest / minutesToDie + 1;
    return ceil(log(buckets) / log(base));
}

int main()
{
    int buckets = 0;
    int minutesToDie = 0;
    int minutesToTest = 0;
    scanf("%d %d %d", &buckets, &minutesToDie, &minutesToTest);
    int result = poorPigs(buckets, minutesToDie, minutesToTest);
    printf("%d", result);

    return 0;
}