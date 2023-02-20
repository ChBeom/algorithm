#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int nterm;
        cin >> nterm;

        vector<int> p(101), q(101);

        // p(x) �Է�
        for (int i = 0; i < nterm; i++) {
            int coef, exp;
            cin >> coef >> exp;
            p[exp] += coef;
        }

        // q(x) �Է�
        cin >> nterm;
        for (int i = 0; i < nterm; i++) {
            int coef, exp;
            cin >> coef >> exp;
            q[exp] += coef;
        }

        // p(x) - q(x) ��� �� ���
        bool nonzero = false;
        for (int i = 100; i >= 0; i--) {
            int diff = p[i] - q[i];
            if (diff != 0) {
                if (nonzero) {
                    if (diff > 0) cout << "+";
                }
                else {
                    nonzero = true;
                }

                if (i == 0) {
                    cout << diff;
                }
                else if (i == 1) {
                    if (diff == 1) {
                        cout << "x";
                    }
                    else if (diff == -1) {
                        cout << "-x";
                    }
                    else {
                        cout << diff << "x";
                    }
                }
                else {
                    if (diff == 1) {
                        cout << "x^" << i;
                    }
                    else if (diff == -1) {
                        cout << "-x^" << i;
                    }
                    else {
                        cout << diff << "x^" << i;
                    }
                }
            }
        }

        if (!nonzero) {
            cout << "0";
        }

        cout << "\n";
    }

    return 0;
}
