#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;

int isUpper(char ch)
{
    return (ch >= 'A' && ch <= 'Z') ? 1 : 0;
}

int isNumber(char ch)
{
    return (ch >= '0' && ch <= '9') ? 1 : 0;
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

bool isValidSection(string section)
{
    if (section.empty())
    {
        return false;
    }

    if (!isUpper(section[0]))
    {
        return false;
    }

    return true;
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
bool customSort(string a, string b)
{
    int sumA = calculateSum(a);
    int sumB = calculateSum(b);

    if (sumA == sumB)
    {
        return a < b; // 使用字符串比较规则
    }

    return sumA < sumB;
}

string removeNonAlphaNumeric(string str)
{
    regex nonAlphaNumeric("[^A-Za-z0-9]");
    return regex_replace(str, nonAlphaNumeric, "");
}

string sortStringBySections(string str)
{
    string realStr = removeNonAlphaNumeric(str);
    vector<string> joints = findJoint(realStr);

    // 移除无效节
    joints.erase(remove_if(joints.begin(), joints.end(), [](auto &section)
                           { return !isValidSection(section); }),
                 joints.end());

    sort(joints.begin(), joints.end(), customSort);

    string sortedString;
    for (auto &joint : joints)
    {
        sortedString += joint;
    }

    return sortedString;
}

int main()
{
    string str;
    cin >> str;

    string sortedString = sortStringBySections(str);
    cout << sortedString << endl;

    return 0;
}