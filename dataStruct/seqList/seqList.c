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
// 第一关
PseqList createNullList_seq(int m)
{ // 此处填写代码，创建一个空的顺序线性表，能存放的最大元素个数为 m
    // 若m=0，则返回NULL
    if (m == 0)
    {
        return NULL;
    }
    PseqList seqList = (struct seqList *)malloc(sizeof(struct seqList));
    seqList->element = (DataType *)malloc(sizeof(DataType) * m);
    seqList->MAXNUM = m;
    seqList->curNum = 0;
    return seqList;
}

// 第二关
int isFullList_seq(PseqList L)
{
    // 判断顺序线性表是否已满，若已满，返回值为1，否则返回值为0
    if (L->MAXNUM == L->curNum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insertP_seq(PseqList head, int p, int x) // 直接看图和树也行啊,为什么不行.
{                                            // 在线性表L中下标为p的位置插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1
    // 如果线性表满了， 还需输"list is full"的提示
    if (isFullList_seq(head))
    {
        printf("list is full");
        return 0;
    }
    // 如果插入位置非法，需输出提示"position is illegel"
    if (p < 0 || p > head->curNum)
    {
        printf("position is illegel");
        return 0;
    }
    // 将位置 [p, curNum-1] 的元素后移一位
    for (int i = head->curNum - 1; i >= p; i--)
    {
        head->element[i + 1] = head->element[i];
    }
    // 在位置 p 插入新元素 x，并
    head->element[p] = x;
    head->curNum++; // 更新 curNum,更新数据表的元素个数
    return 1;
}

int insertPre_seq(PseqList shunXuList, int p, int x)
{
    // 在线性表L中下标为p的位置的前面插入数据元素x
    // 若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1

    // if (isFullList_seq(shunXuList))
    // {
    //     return 0;
    // }
    // if (p < 0 || p > shunXuList->curNum)
    // {
    //     return 0;
    // }

    // 多此一举了,因为可以直接在insertP_seq里面做判断.

    // 提示：直接调用insertP函数实现即可
    return insertP_seq(shunXuList, p - 1, x);
}

int insertPost_seq(PseqList shunXuList, int p, int x)
{
    // 在线性表L中下标为p的位置的后面插入数据元素x，若下标p非法或线性表已满无法插入数据，返回0；插入成功返回值为1

    // 多此一举了,因为可以直接在insertP_seq里面做判断.

    // 提示：直接调用insertP函数实现即可
    return insertP_seq(shunXuList, p + 1, x);
}

void printList_seq(PseqList L)
{ // 逐个输出线性表的元素，相邻的两个数据元素之间以一个空格为分隔符隔开
    for (int i = 0; i < L->curNum; i++)
    {
        printf("%d ", L->element[i]);
    }
    printf("\n");
}

// 第三关
int destroyList_seq(PseqList shunXuList)
{
    // 返回值为销毁的线性表中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    if (shunXuList == NULL)
    {
        return 0;
    }
    int dataNum = shunXuList->curNum;
    free(shunXuList);
    return dataNum;
}

// 第四关
int locate_seq(PseqList L, int x)
{ // 在顺序表L中查找给定值x首次出现的位置，若不存在给定值，则返回-1
    for (int i = 0; i < L->curNum; i++)
    {
        if (L->element[i] == x)
        {
            return i;
        }
    }
    return -1;
}

DataType locatePos_seq(PseqList L, int pos)
{ // 在顺序表L中查找指定位置pos处的数据元素，若位置非法，则返回第0个数据元素
    if (pos < 0 || pos >= L->curNum)
    {
        return L->element[0];
    }
    return L->element[pos];
}

// 第五关
int deletePos_seq(PseqList L, int pos)
{
    // 在顺序表L中删除在下标pos处的数据元素，若pos非法，则返回-1；否则返回1
    if (pos < 0 || pos >= L->curNum) // 应该是或者:or,不是and
    {
        return -1;
    }
    for (int i = pos; i < L->curNum; i++)
    {
        // pos, 223, 245, 276
        L->element[i] = L->element[i + 1]; // 从pos位置开始向后遍历,全部前移1位
    }
    L->curNum--; // 别忘记更新现有元素的个数
    return 1;
}

int delete_seq(PseqList L, int x)
{ // 在顺序表L中删除与参数x值相同的数据元素，返回删除数据元素的个数
    // 可以使用之前已完成的操作

    int deleteNum = 0;
    int deleteLoc = locate_seq(L, x);
    while (deleteLoc != -1)
    {

        deletePos_seq(L, deleteLoc);
        deleteNum++;
        deleteLoc = locate_seq(L, x);
    }
    return deleteNum;
}

// 第六关
void replace_seq(PseqList L, int x, int y)
{                                           // 将顺序表L中值为x的数据元素替换为y
    int findNumLocation = locate_seq(L, x); // 找到返回index,没找到返回-1
    while (findNumLocation != -1)
    {
        L->element[findNumLocation] = y;
        findNumLocation = locate_seq(L, x);
    }
    L->curNum++;
}

void delDuplicate_seq(PseqList L)
{
    int hashSize = 100;
    int *hashMap = (int *)malloc(sizeof(int) * hashSize);
    for (int i = 0; i < curNum + 1; i++)
    {
        hashMap[i] = 0; // 初始化哈希表为0
    }

    for (int i = 0; i < L->curNum; i++)
    {
        hashMap[L->element[i]]++; // 因为测试案例中输入-1,导致数组越界,所以不能使用普通的哈希表,而是通过哈希函数映射的方式存储
    }

    for (int i = 0; i < L->curNum; i++)
    {
        if (hashMap[L->element[i]] > 1) // 找到重复元素
        {
            delete_seq(L, L->element[i]);
        }
    }
}

int main(void)
{
    int m, x;
    scanf("%d", &m);
    PseqList head = createNullList_seq(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        insertP_seq(head, i, x);
    }
    scanf("%d%d", &m, &x);
    printList_seq(head);
    replace_seq(head, m, x);
    printList_seq(head);
    delDuplicate_seq(head);
    printList_seq(head);
    destroyList_seq(head);
}