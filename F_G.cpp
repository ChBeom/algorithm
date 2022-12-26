#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t = 0;
	int cow[400][400] = { 0 };

	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> cow[i][j];
		}
	}
	int tt = t;
	for (int i = 0; i < t; i++) {
		tt -= 1;
		for (int j = 0; j < t - i; j++) {
			if (tt != 0) {
				if (cow[tt][j] + cow[tt - 1][j] > cow[tt - 1][j] + cow[tt][j + 1]) {
					cow[tt - 1][j] = cow[tt][j] + cow[tt - 1][j];
				}
				else {
					cow[tt - 1][j] = cow[tt - 1][j] + cow[tt][j + 1];
				}
			}
		}
	}
	cout << cow[0][0];
}