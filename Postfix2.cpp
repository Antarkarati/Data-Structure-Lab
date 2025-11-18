#include <iostream>
using namespace std;

#define MAX 100

int stk[MAX];
int topIndex = -1;

void push(int x)
{
    stk[++topIndex] = x;
}

int pop()
{
    return stk[topIndex--];
}

int topValue()
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

bool getNextToken(string &exp, int &pos, string &token)
{
    token = "";

    // skip spaces
    while (pos < exp.size() && exp[pos] == ' ')
        pos++;

    if (pos >= exp.size())
        return false;

    // read characters until space
    while (pos < exp.size() && exp[pos] != ' ')
    {
        token += exp[pos];
        pos++;
    }

    return true;
}

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    getline(cin, exp);

    cout << "\nSymbol\t\tStack\n";
    cout << "-----------------------------\n";

    int pos = 0;
    string token;

    while (getNextToken(exp, pos, token))
    {
        cout << token << "\t\t";

        // If number
        if (isdigit(token[0]))
        {
            push(stoi(token));
        }
        else
        {
            // Operator
            int b = pop();
            int a = pop();
            int r = 0;

            if (token == "+")
                r = a + b;
            else if (token == "-")
                r = a - b;
            else if (token == "*")
                r = a * b;
            else if (token == "/")
                r = a / b;

            push(r);
        }

        printStack();
        cout << endl;
    }

    cout << "\nFinal Result = " << topValue() << endl;

    return 0;
}
