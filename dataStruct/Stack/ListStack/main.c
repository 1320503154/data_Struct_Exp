#include <stdio.h>
#include <stdlib.h>

/*此处是链栈数据结构定义*/
typedef char DataType;
struct node
{
    DataType data;
    struct node *next;
};

typedef struct node *PNode;

struct LinkStack
{
    PNode top;
};
typedef struct LinkStack *PLinkStack;

PNode createNode(DataType val)
{
    PNode newNode = (PNode)malloc(sizeof(PNode));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// 第一关
PLinkStack createNullStack_link()
{ // 此处填写代码，创建一个空的链栈

    PLinkStack s = (PLinkStack)malloc(sizeof(PLinkStack));
    s->top = NULL; // 初始化为NULL
    return s;
}

// 第二关
int isNullStack_link(PLinkStack L)
{
    // 判断栈是否为空，若为空，返回值为1，否则返回值为0,若栈不存在，则返回-1
    if (L == NULL)
    {
        return -1;
    }
    return (L->top == NULL) ? 1 : 0;
}

// 第三关
int push_link(PLinkStack L, DataType x)
{ // 在栈中插入数据元素x，若插入不成功，返回0；插入成功返回值为1
    if (L == NULL)
    {
        return 0;
    }
    PNode newNode = createNode(x);
    if (newNode == NULL)
    {
        return 0;
    }
    newNode->next = L->top; // 之前的栈顶.
    L->top = newNode;
    return 1;
}

// 第四关
DataType pop_link(PLinkStack L)
{ // 弹栈并返回删除元素，若栈为空，则返回-1
    if (isNullStack_link(L))
    {
        return -1;
    }
    DataType data = L->top->data;
    PNode temp = L->top;
    L->top = L->top->next; // 移动到之前的栈顶
    free(temp);
    return data;
}

// 第五关
DataType top_link(PLinkStack L)
{ // 取栈顶元素返回，若栈为空，则返回-1
    if (isNullStack_link(L))
    {
        return -1;
    }
    return L->top->data;
}

// 销毁栈，释放栈所占存储空间
int destroystack_link(PLinkStack L)
{
    // 返回值为销毁的栈中现有数据元素的个数，若待销毁的线性表不存在，则返回0
    int cnt = 0;
    if (L == NULL)
        return 0;
    struct node *p = L->top, *q;
    free(L);
    while (p->next != NULL)
    {
        q = p->next;
        cnt++;
        free(p);
        p = q;
    }
    return cnt;
}

// 第六关
char getClosingBracket(char opening)
{
    switch (opening)
    {
    case '(':
        return ')';
    case '{':
        return '}';
    case '[':
        return ']';
    default:
        return 0;
    }
}
int balance_symbol(char *s)
{ // 在此处填写代码完成符号配对判断，若配对，返回值为1，否则返回值为0
    PLinkStack charStack = createNullStack_link();
    int i = 0;
    while (s[i] != "\0") // 结束字符
    {
        char ch = s[i];
        switch (ch)
        {
        case '(':
        case '{':
        case '[':
            push_link(charStack, getClosingBracket(ch));
            break;

        default:
            if (isNullStack_link(charStack) || top_link(charStack) != ch)
            {
                return false;
            }
            pop_link(charStack); // charStack.top() 与 s[i]相等，栈弹出元素
            break;
        }
        i++; // 走i指针
    }
    return isNullStack_link(charStack);
}
