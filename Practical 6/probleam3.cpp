#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;

    if (op == '*' || op == '/')
        return 2;

    if (op == '^')
        return 3;

    return 0;
}

string infixToPostfix(string expression)
{
    stack<char> s;
    string result = "";

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
        {
            result += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                result += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() && s.top() != '(' &&
                   priority(s.top()) >= priority(ch))
            {
                result += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        result += s.top();
        s.pop();
    }

    return result;
}

int main()
{
    string expression;

    cout << "Enter infix expression: ";
    getline(cin, expression);

    cout << "Postfix expression: ";
    cout << infixToPostfix(expression) << endl;

    return 0;
}