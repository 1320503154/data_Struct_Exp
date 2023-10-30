#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node
{
    int key; // 为什么要在链表中同时存储 key 和 val，而不是只存储 val 呢？
             // 答案很简单，因为删除节点时，需要该节点的 key。
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class DoubleList
{

private:
    // 头尾虚节点
    Node *head;
    Node *tail;
    // 链表元素数
    int size;

public:
    DoubleList() : size(0)
    {
        // 初始化双向链表的数据
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    // 在链表尾部添加节点 x，时间 O(1)
    void addLast(Node *x)
    {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }
    // 删除链表中的 x 节点（x 一定存在）
    // 由于是双链表且给的是目标 Node 节点，时间 O(1)
    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }
    // 删除链表中第一个节点，并返回该节点，时间 O(1)
    Node *removeFirst()
    {
        if (head->next == tail)
            return nullptr;
        Node *first = head->next;
        remove(first);
        return first;
    }
    // 返回链表长度，时间 O(1)
    int getSize()
    {
        return size;
    }
};

class LRUCache
{
private:
    // key -> Node(key, val)
    std::unordered_map<int, Node *> map;
    // Node(k1, v1) <-> Node(k2, v2)...
    DoubleList cache;
    // 最大容量
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        cache = new DoubleList();
        map = new unordered_map<int, Node *>(); // 初始化指定泛型
    }
    // 打开一个新的软件,使其是最近使用的软件
    void makeRecently(int key)
    {
        Node *x = map[key];
        // 先从链表中删除这个节点
        cache.remove(x);
        // 重新插到队尾
        cache.addLast(x);
    }
    /* 添加最近使用的软件 */
    void addRecently(int key, int val)
    {
        // 将对节点的操作分配在抽象的函数中,集中操作
        Node *x = new Node(key, val);
        cache.addLast(x);
        map[key] = x;
    }
    /* 删除一个软件的内存 */
    void deleteKey(int key)
    {
        Node *x = map[key];
        cache.remove(x);
        map.erase(key);
    }
    // 删除链表的表头软件,因为表头代表不使用的软件.
    void removeLeastRecently()
    {
        Node *deletedNode = cache.removeFirst();
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
        delete deletedNode;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        if (!map.count(key))
        {
            return -1;
        }
        makeRecently(key);
        return map[key]->val;
    }

    void put(int key, int val)
    {
        if (map.count(key))
        {
            deleteKey(key);
            addRecently(key, val);
            return;
        }
        if (cache.getSize() == capacity)
        {
            removeLeastRecently();
        }
        addRecently(key, val);
    }
};