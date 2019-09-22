#include <stack>
#include <iostream>
#include <string>

using namespace std;

int n;
stack<int> s;

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int num;
			cin >> num;

			s.push(num);
		}
		else if (command == "pop") {
			if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
			else
				printf("-1\n");
		}
		else if (command == "size") {
			printf("%d\n", s.size());
		}
		else if (command == "empty") {
			printf("%d\n", s.empty());
		}
		else if (command == "top") {
			if (!s.empty()) {
				printf("%d\n", s.top());
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}