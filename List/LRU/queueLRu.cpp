// #include <unordered_map>
// #include <vector>
// #include <queue>
// #include <string>
// #include <iostream>
// using namespace std;
// class LRUCache
// {
// private:
//     int capacity;
//     int timestamp;
//     unordered_map<int, pair<int, int>> cache;
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

// public:
//     LRUCache(int capacity)
//     {
//         this->capacity = capacity;
//         timestamp = 0;
//     }

//     int get(int key)
//     {
//         if (cache.find(key) != cache.end())
//         {
//             // 更新使用时间戳
//             cache[key].second = timestamp++;
//             return cache[key].first;
//         }
//         return -1;
//     }

//     void put(int key, int value)
//     {
//         if (cache.size() == capacity && cache.find(key) == cache.end())
//         {
//             // 缓存已满，需要删除最久未使用的元素
//             while (!heap.empty() && cache[heap.top().second].second != heap.top().first)
//             {
//                 heap.pop();
//             }
//             if (!heap.empty())
//             {
//                 cache.erase(heap.top().second);
//                 heap.pop();
//             }
//         }
//         // 更新使用时间戳并添加到缓存和堆中
//         cache[key] = make_pair(value, timestamp++);
//         heap.push(make_pair(timestamp, key));
//     }
// };
// int main()
// {

//     vector<pair<int, string>> myVector;

//     // 向向量中添加键值对
//     myVector.push_back(make_pair(1, "Hello"));
//     myVector.emplace_back(2, "World");

//     // 遍历并打印键值对
//     for (const auto &pair : myVector)
//     {
//         int key = pair.first;
//         string value = pair.second;
//         cout << "Key: " << key << ", Value: " << value << endl;
//     }
// }
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    // 对于基础类型 默认是大顶堆,堆(heap)就是完全二叉树,父节点都大于子节点.
    priority_queue<int> a;
    // 等同于 priority_queue<int, vector<int>, less<int> > a;

    priority_queue<int, vector<int>, greater<int>> c; // 这样就是小顶堆,父节点都小于子节点
    priority_queue<string> b;
    cout << "print a:" << endl;
    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;
    cout << "print c:" << endl;

    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;
    cout << "print b:" << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;
    return 0;
}
