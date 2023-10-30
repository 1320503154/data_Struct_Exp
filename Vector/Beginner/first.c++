#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    // 创建空的 vector
    vector<int> vec;

    // 向 vector 中添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 访问 vector 中的元素
    cout << "Vector elements: ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // 修改 vector 中的元素
    vec[1] = 50;

    // 删除 vector 中的最后一个元素
    vec.pop_back();
    // 动态添加一些奇怪的东西
    vec.push_back(30);
    vec.push_back(15);
    vec.push_back(12);
    vec.push_back(14);
    vec.push_back(9);

    // 使用算法库的函数排序
    sort(vec.begin(), vec.end());

    // 使用迭代器遍历 vector
    cout
        << "Vector elements (using iterator): ";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " "; // 此处的it是一个指针
    }
    cout << endl;

    // 清空 vector
    vec.clear();
    // 清空所有数据,然后释放内存:: vector<int>().swap(vec)

    // 检查 vector 是否为空
    if (vec.empty()) // 为空 return 1;
    {
        cout << "容器的长度为: " << vec.empty() << endl
             << "Vector is empty." << endl;
    }

    return 0;
}