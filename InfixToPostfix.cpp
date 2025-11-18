#include <iostream>
using namespace std;

#define MAX 100

char stk[MAX];
int topIndex = -1;

void push(char c)
{
    stk[++topIndex] = c;
}

char pop()
{
    return stk[topIndex--];
}

char topValue()
{
    return stk[topIndex];
}

bool isEmpty()
{
    return topIndex == -1;
}

void printStack()
{
    if (isEmpty())
    {
        cout << "empty";
        return;
    }
    for (int i = 0; i <= topIndex; i++)
    {
        cout << stk[i] << " ";
    }
}

int priority(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = "";

    cout << "\nSymbol\t\tStack\t\tExpression\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < infix.length(); i++)
    {
        char s = infix[i];

        cout << s << "\t\t";

        if (isalnum(s))
        {
            postfix += s;
        }

        else if (s == '(')
        {
            push(s);
        }

        else if (s == ')')
        {
            while (!isEmpty() && topValue() != '(')
            {
                postfix += pop();
            }
            pop();
        }

        else
        {
            while (!isEmpty() && priority(topValue()) >= priority(s))
            {
                postfix += pop();
            }
            push(s);
        }

        printStack();
        cout << "\t\t";

        cout << postfix;

        cout << endl;
    }

    while (!isEmpty())
    {
        postfix += pop();
    }

    cout << "\nFinal Postfix Expression: " << postfix << endl;

    return 0;
}
