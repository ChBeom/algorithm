#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack <string> foward_stack;
	stack <string> backward_stack;
	string order;
	string url;
	string b_url;
	string f_url;

	while (1)
	{
		cin >> order;

		if (order.compare("VISIT") == 0) {
			cin >> url;
			cout << url << endl;
			if (backward_stack.empty()) {
				backward_stack.push("http://www.acm.org/");
				if (!foward_stack.empty()) {
					foward_stack.pop();
				}
			}
			else {
				backward_stack.push(b_url);
				if (!foward_stack.empty()) {
					foward_stack.pop();
				}
			}
			b_url = url;
			f_url = url;
		}
		else if (order.compare("BACK") == 0) {
			if (backward_stack.empty()) {
				cout << "Ignored" << endl;
			}
			else {
				cout << backward_stack.top() << endl;
				foward_stack.push(f_url);
				url = backward_stack.top();
				f_url = url;
				b_url = url;
				backward_stack.pop();
			}
		}
		else if (order.compare("FORWARD") == 0) {
			if (foward_stack.empty()) {
				cout << "Ignored" << endl;
			}
			else {
				cout << foward_stack.top() << endl;
				backward_stack.push(b_url);
				url = foward_stack.top();
				b_url = url;
				f_url = url;
				foward_stack.pop();
			}
		}
		else if (order.compare("QUIT") == 0) {
			break;
		}
	}
}