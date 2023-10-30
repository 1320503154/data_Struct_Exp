#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_TABLE_LEN 100
using namespace std;
// int find_key(vector<int> array, int key)
// {
//     for (int i = 0; i < array.size(); i++)
//     {
//         if (key == array[i])
//         {
//             return 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     vector<int> a = {7, 17, 5, 8, 2, 9, 20, 3, 2, 5};
//     // 查找1到10是否在a中
//     for (int i = 1; i <= 10; i++) // 10次,整体的时间复杂度为O(n^2)
//     {
//         if (find_key(a, i)) // 每次循环都要遍历一遍a数组,10次
//         {
//             cout << i << "在a数组中" << endl;
//         }
//         else
//         {
//             cout << i << "不在a数组中" << endl;
//         }
//     }
// }
void create_hash(vector<int> &array, vector<int> &table)
{
    for (int i = 0; i < array.size(); i++)
    {
        table[array[i]]++; // 用array[i]作为下标,table[array[i]]作为值,存储array[i]出现的次数,也就是array中元素的个数.
    }
}
int main()
{
    vector<int> a = {7, 17, 5, 8, 2, 9, 20, 3, 2, 5};
    vector<int> table(MAX_TABLE_LEN, 0);

    create_hash(a, table);

    cout << "In hash table:" << endl;
    for (int i = 0; i < MAX_TABLE_LEN; i++)
    {
        if (table[i] > 0)
        {
            cout << i << " appear " << table[i] << " times." << endl;
        }
    }
}