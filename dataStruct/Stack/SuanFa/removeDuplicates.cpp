#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st; // 创建一个int类型的栈对象st

    st.push(10); // 压入元素10到栈顶
    st.push(20); // 压入元素20到栈顶
    st.push(30); // 压入元素30到栈顶

    cout << "Top element: " << st.top() << endl; // 访问栈顶元素并打印

    st.pop(); // 弹出栈顶元素

    if (st.empty())
    { // 检查栈是否为空
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }

    cout << "Stack size: " << st.size() << endl; // 输出栈的大小

    return 0;
}
// wrong:
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> charStack;
        for (int i = 0; i < s.size(); i++)
        {
            charStack.push(s[i]);
            if (s[i] == charStack.top() && !charStack.empty())
            {
                charStack.pop();
            }
        }
        string result = "";
        while (!charStack.empty())
        {
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
    }
};
// right:
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> charStack;

        for (int i = 0; i < s.size(); i++)
        {
            charStack.push(s[i]);

            if (!charStack.empty() && s[i] == charStack.top())
            {
                charStack.pop();
            }
        }

        string result = "";
        while (!charStack.empty())
        {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }
};