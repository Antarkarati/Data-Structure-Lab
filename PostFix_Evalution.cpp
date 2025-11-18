#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>
using namespace std;

// Print stack content as a string
string getStackContent(stack<int> s) {
    string out = "";
    while (!s.empty()) {
        out = to_string(s.top()) + " " + out;
        s.pop();
    }
    return out;
}

int main() {
    string postfix;
    cout << "Enter postfix expression (space separated): ";
    getline(cin, postfix);

    stack<int> st;
    stringstream ss(postfix);
    string token;

    cout << left << setw(15) << "Symbol"
         << "Stack" << endl;
    cout << "----------------------------\n";

    while (ss >> token) {
        cout << left << setw(15) << token;

        // If operand (number)
        if (isdigit(token[0])) {
            st.push(stoi(token));
        } 
        else {
            // Operator
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int result = 0;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") result = a / b;

            st.push(result);
        }

        cout << getStackContent(st) << endl;
    }

    cout << "\nFinal Result = " << st.top() << endl;

    return 0;
}
