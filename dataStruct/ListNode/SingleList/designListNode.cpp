#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class MyLinkedList
{

public:
    struct LinkedList
    {
        int val;
        struct LinkedList *next;
        LinkedList(int x) : val(x), next(nullptr) {}
    };
    MyLinkedList()
    {
        dummyHead = new LinkedList(0);
        size = 0;
    }
    // 操作链表任何一个节点,都要知道链表的前一个节点
    int get(int index)
    {
        if (index < 0 || index > size - 1)
        {
            return -1;
        }
        auto cur = dummyHead->next; // 只有在get函数中,cur = dummyHead->next
        while (index)               // index=0;返回头节点的值
        {
            cur = cur->next;
            index--;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        // add,首先肯定创建一个空节点啊.
        auto newNode = new LinkedList(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
        // 别忘记size++
    }

    void addAtTail(int val)
    {
        auto newNode = new LinkedList(val);
        auto cur = dummyHead; // 此处的cur还是虚拟头节点,其实next也行
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        // 此时cur是尾节点了
        cur->next = newNode;
        size++;
    }
    // 在第index个节点之前插入一个新节点,index=0,则添加新的头节点
    // 若index=链表的长度,则插入的为尾节点
    void addAtIndex(int index, int val)
    {
        // 缺少对下标的判定
        if (index > size)
        {
            return;
        }
        if (index < 0)
        {
            index = 0;
        }
        // 缺少对下标的判定
        auto newNode = new LinkedList(val);
        auto cur = dummyHead; // 虚拟头节点
        while (index)
        {
            cur = cur->next;
            index--;
        }
        // 此时cur是index处的前一个节点
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    // 删除第index个节点.index从0开始
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        auto cur = dummyHead;
        while (index)
        {
            cur = cur->next;
            index--;
        }
        auto temp = cur->next; // 经典手动管理内存
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        size--;
    }
    void printLinkedList()
    {
        auto cur = dummyHead;
        while (cur->next != nullptr)
        {

            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    int size;
    LinkedList *dummyHead;
};
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    int index = 1;
    int val = 30;
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index, val);
    obj->deleteAtIndex(index);
    obj->printLinkedList();
}