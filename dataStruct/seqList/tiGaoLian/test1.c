#include "../seqlist.h"

int main()
{
    int num, data;
    int i;
    scanf("%d", &num);
    PseqList plist = createNullList_seq(num); // num = 6
    for (i = 0; i < num; i++)
    {
        scanf("%d", &data);
        insertP_tail(plist, data); // 在表尾插入元素
    }
    printf("%d", seqMaxSum(plist));
}