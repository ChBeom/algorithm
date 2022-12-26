#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int d[10001] = { 0 };

void DP() { // 1 3 7 12
    d[1] = 1;
    d[2] = 2;
    d[3] = 1;
    d[4] = 2;
    d[5] = 3;
    d[6] = 2;
    d[7] = 1;
    d[8] = 2;
    d[9] = 3;
    d[10] = 2;
    d[11] = 3;
    d[12] = 1;

    int n = 0;
    int m_a = 0;
    int m_b = 0;

    cin >> n;

    for (int i = 13; i <= n; i++) {
        m_a = min(d[i - 1], d[i - 3]) + 1;
        m_b = min(d[i - 7], d[i - 12]) + 1;
        d[i] = min(m_a, m_b);

    }
    cout << d[n] << endl;
}

int main() {
    int Testcase = 0;

    cin >> Testcase;
    for (int i = 0; i < Testcase; i++) {
        DP();
    }
}