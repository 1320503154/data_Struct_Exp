#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_TABLE_LEN 100
using namespace std;
int int_func(int key)
{
    return key % MAX_TABLE_LEN;
}
int string_func(const char *key) // 接受的是字符串的首地址(第一个字符的地址)
{
    int sum = 0;
    while (*key) // *key != '\0' , 遍历字符串中的字符
    {
        sum += *key; // 将字符串中的每个字符的ASCII码相加
        key++;
    }
    return sum % MAX_TABLE_LEN; // 用字符串的ASCII码之和对MAX_TABLE_LEN取余
}
int find_key(vector<int> &table, int key)
{
    return table[int_func(key)] != 0;
    // 如果table[int_func(key)]不为0,则返回1,表示找到了key,否则返回0,表示没找到key
}
int main()
{
    vector<int> hashTable(MAX_TABLE_LEN, 0);

    hashTable[int_func(523)]++;

    hashTable[int_func(23)]++;

    hashTable[string_func("abc")]++;

    hashTable[string_func("cba")]++;

    cout << "In hash table:" << endl;
    for (int i = 0; i < hashTable.size(); i++)
    {
        if (hashTable[i] > 0)
        {
            printf("table[%d] = %d\n", i, hashTable[i]);
        }
    }
    cout << "find_key(523): " << find_key(523) ? "true" : "false" << endl;
    return 0;
}