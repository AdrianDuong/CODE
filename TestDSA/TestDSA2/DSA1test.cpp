#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ignore newline character after t

    while (t--) {
        string expression;
        getline(cin, expression);

        // Replace '*' with '-1'
        while (expression.find('*') != string::npos) {
            expression.replace(expression.find('*'), 1, "-1");
        }

        stack<int> s;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '(') {
                s.push(i);
            } else if (expression[i] == ')') {
                if (!s.empty()) {
                    int start = s.top();
                    s.pop();
                    expression[start] = '0';
                    expression[i] = '1';
                } else {
                    expression[i] = '-1';
                }
            }
        }

        while (!s.empty()) {
            int start = s.top();
            s.pop();
            expression[start] = '-1';
        }

        cout << expression << endl;
    }

    return 0;
}
