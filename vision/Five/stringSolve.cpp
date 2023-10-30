#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <stdbool.h>
using namespace std;
int isUpper(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ? 1 : 0;
}
int isLow(char ch)
{
    return (ch >= 'a' && ch <= 'z') ? 1 : 0;
}
int isNumber(char ch)
{
    return (ch >= '0' && ch <= '9') ? 1 : 0;
}
int isVaild(char ch)
{
    return (isUpper(ch) || isLow(ch) || isNumber(ch)) ? 1 : 0;
}

vector<string> findJoint(string input)
{
    regex uppercase("[A-Z]");
    string temp = regex_replace(input, uppercase, "_$0");
    vector<string> joint;
    size_t pos = 0;

    while ((pos = temp.find("_")) != string::npos)
    {
        joint.push_back(temp.substr(0, pos));
        temp.erase(0, pos + 1);
    }

    joint.push_back(temp);

    return joint;
}
int calculateSum(string nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (isNumber(nums[i]))
        {
            result += (nums[i] - '0');
        }
    }
    return result;
}
bool customSort(string a, string b)
{
    int sumA = calculateSum(a);
    int sumB = calculateSum(b);

    if (sumA == sumB)
    {
        return a < b; // 直接拿c++的字符串比较规则比较即可
    }

    return sumA < sumB;
}
// string removeNonAlphaNumeric(string str)
// {
//     regex nonAlphaNumeric("[^A-Za-z0-9]");
//     return regex_replace(str, nonAlphaNumeric, "");
// }
string sortStringBySections(string str)
{
    string realStr;
    for (int i = 0; i < str.size(); i++)
    {
        if (isVaild(str[i]))
        {
            realStr.push_back(str[i]);
        }
    }
    vector<string> joints = findJoint(realStr);
    sort(joints.begin(), joints.end(), customSort); // 根据后面函数的排序规则排序

    string sortedString;
    for (const string &joint : joints)
    {
        sortedString += joint;
    }

    return sortedString;
}
int main()
{
    // 找到字符串里面的数字,求和为realSize
    // 按realSize排序 to sort
    // 一个大写字母,遇到下一个大写字母算一节.
    // Abc6u7iF8s5xRH2Tk99
    // 分节：Abc6u7i F8s5x R H2 Tk99.
    // 然后根据数字运算结果排序,如果真实大小相等,则看字符串的首字母大小
    string str;
    cin >> str;

    string sortedString = sortStringBySections(str);
    cout << sortedString;
    return 0;
}
