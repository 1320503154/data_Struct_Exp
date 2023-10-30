#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    list<string> myList;

    // 插入元素
    myList.push_back("apple");
    myList.push_back("banana");
    myList.push_front("cherry");
    printf("下列是迭代器for输出的\n");
    // 遍历打印元素
    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // 删除元素
    myList.pop_front();

    // 修改元素
    *myList.begin() = "grape";
    printf("const auto &elem : myList for循环打印的\n");
    // 遍历打印元素
    for (const auto &elem : myList)
    {
        cout << elem << " ";
    }
    cout << endl;

    // 查找元素
    if (find(myList.begin(), myList.end(), "banana") != myList.end())
    {
        cout << "Found banana!" << endl;
    }

    // 排序
    myList.sort();
    printf("排序后打印函数\n");
    // 遍历打印元素
    for (const auto &elem : myList)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}