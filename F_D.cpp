#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main() {
	int Testcase = 0;
	int n = 0;
	int ID = 0;
	string order;


	cin >> Testcase;

	for (int i = 0; i < Testcase; i++) {
		cin >> n;
		queue <int> scv;
		for (int j = 0; j < n; j++) {
			cin >> order;
			if (order.compare("In") == 0) {
				cin >> ID;
				scv.push(ID);
			}
			else if (order.compare("Out") == 0) {
				if (scv.empty()) {
					cout << "Empty" << endl;
				}
				else {
					cout << scv.front() << endl;
					scv.pop();
				}
			}
		}
	}
}