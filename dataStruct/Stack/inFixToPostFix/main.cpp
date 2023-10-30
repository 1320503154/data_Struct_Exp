#include <iostream>
#include <stack>
#include <string>
using namespace std;
// 定义运算符的优先级
int getPriority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 判断是否为操作符
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 将中缀表达式转换为后缀表达式
string infixToPostfix(string infix)
{
    string postfix;
    stack<char> operatorStack;

    // 遍历中缀表达式的每个字符
    for (char c : infix)
    {
        // 如果是操作数，直接添加到后缀表达式中
        if (isalnum(c))
        {
            postfix += c;
        }
        // 如果是左括号，入栈
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        // 如果是右括号，将栈内的操作符弹出并添加到后缀表达式中，直到遇到左括号
        else if (c == ')')
        {
            while (!operatorStack.empty() && operatorStack.top() != '(')
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // 弹出左括号
            if (!operatorStack.empty() && operatorStack.top() == '(')
            {
                operatorStack.pop();
            }
        }
        // 如果是操作符
        else if (isOperator(c))
        {
            // 将栈内优先级高于或等于当前操作符的操作符弹出并添加到后缀表达式中
            while (!operatorStack.empty() && getPriority(operatorStack.top()) >= getPriority(c))
            {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            // 当前操作符入栈
            operatorStack.push(c);
        }
    }

    // 将栈内剩余的操作符弹出并添加到后缀表达式中
    while (!operatorStack.empty())
    {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main()
{

    string infixExp;
    cout << "请输入中缀表达式: ";
    getline(cin, infixExp);

    string postfixExp = infixToPostfix(infixExp);
    cout << "后缀表达式: " << postfixExp << endl;

    return 0;
}