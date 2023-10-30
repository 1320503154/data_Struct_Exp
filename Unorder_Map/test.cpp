#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, string> mymap; // 创建一个空的 unordered_map

    mymap["key"] = "value"; // 插入键值对
    mymap["key2"] = "value2";

    cout << mymap["key"] << endl; // 访问键对应的值
    cout << mymap["key2"] << endl;

    // mymap.erase("key"); // 删除键值对

    for (auto &pair : mymap)
    { // 遍历键值对
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}