#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operator
char associativity(char c) {
    if (c == '^')
        return 'R'; // Right-associative
    return 'L';     // Left-associative
}

// Function to convert infix to postfix expression
string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If operand, add to output
        if (isalnum(c)) {
            result += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        // If operator
        else {
            while (!st.empty() && 
                   (prec(c) < prec(st.top()) || 
                   (prec(c) == prec(st.top()) && associativity(c) == 'L'))) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all remaining operators
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

// Function to generate three-address code
void generateIntermediateCode(string postfix) {
    stack<string> st;
    int tempVarCount = 1;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalpha(c) || isdigit(c)) {
            string op(1, c);
            st.push(op);
        } else {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            string tempVar = "t" + to_string(tempVarCount++);
            cout << tempVar << " = " << operand1 << " " << c << " " << operand2 << endl;
            st.push(tempVar);
        }
    }
}

int main() {
    string exp;
    cout << "Enter an infix expression: ";
    getline(cin, exp);

    string postfix = infixToPostfix(exp);
    cout << "Postfix Expression: " << postfix << endl;

    generateIntermediateCode(postfix);
    return 0;
}
