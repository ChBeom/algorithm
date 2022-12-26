#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

bool is_digit(string str) {
    return atoi(str.c_str()) != 0 || str.compare("0") == 0; // 0이면 문자 1이면 숫자
}

int main() {
    int Testcase = 0;

    cin >> Testcase;
    for (int i = 0; i < Testcase; i++) {
        int nterm = 0;
        stack <string> sum;
        string s;
        int a, b, c;

        cin >> nterm;
        for (int j = 0; j < nterm; j++) {
            cin >> s;
            if (is_digit(s) == 1) {
                sum.push(s);
            }
            else if (s.compare("+") == 0) {
                if (sum.size() > 1) {
                    b = stoi(sum.top());
                    sum.pop();
                    a = stoi(sum.top());
                    sum.pop();
                    c = a + b;
                    sum.push(to_string(c));
                }
                else {
                    break;
                }
            }
            else if (s.compare("-") == 0) {
                if (sum.size() > 1) {
                    b = stoi(sum.top());
                    sum.pop();
                    a = stoi(sum.top());
                    sum.pop();
                    c = a - b;
                    sum.push(to_string(c));
                }
                else {
                    break;
                }
            }
            else if (s.compare("*") == 0) {
                if (sum.size() > 1) {
                    b = stoi(sum.top());
                    sum.pop();
                    a = stoi(sum.top());
                    sum.pop();
                    c = a * b;
                    sum.push(to_string(c));
                }
                else {
                    break;
                }
            }
            else if (s.compare("/") == 0) {
                if (sum.size() > 1) {
                    b = stoi(sum.top());
                    sum.pop();
                    a = stoi(sum.top());
                    sum.pop();
                    c = a / b;
                    sum.push(to_string(c));
                }
                else {
                    break;
                }
            }
        }
        if (sum.size() == 1) {
            cout << sum.top() << endl;
        }
        else {
            cout << "Incorrect Expression!" << endl;
        }
    }
}