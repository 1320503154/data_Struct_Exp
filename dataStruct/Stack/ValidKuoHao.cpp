#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        // std::string是标准库中的一个类，它提供了许多成员函数来操作字符串。
        // 其中一个成员函数是size()，用于返回字符串的大小，即字符串中字符的数量。
        int len = s.length();
        if (len % 2 != 0)
            return false;
        stack<char> st;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                st.push(')');
            }
        }
        // 此时遍历完s字符串
        return st.empty(); // Returns true if the %stack is empty.
        // 如果栈为空,说明全部匹配上了
    }
};